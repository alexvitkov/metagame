
export interface Progress {
  loaded: number;
  total: number;
}

export type Loader = (url: string) => Promise<any>;
export type Manifest = Map<string, Loader>;
export type Assets = Map<string, any>;

export async function load(assets: Manifest, progressCallback?: (Progress) => any): Promise<Assets> {
  const progress: Progress = {
    loaded: 0,
    total: assets.size,
  };

  let promises = [];
  let loadedAssets: Assets = new Map();

  for (const [url, loader] of assets)
    promises.push(loadAsset(url, loader, progress, progressCallback, loadedAssets));
  
  await Promise.all(promises);
  return loadedAssets;
}

async function loadAsset(url: string, loader: Loader, progress: Progress, progressCallback, results: Assets) {
  const asset = await loader(url);

  progress.loaded++;
  progressCallback?.(progress);

  results.set(url, asset);
  return asset;
}

export async function loadText(url: string): Promise<string> {
  const resp = await fetch(url);
  return await resp.text();
}

export function loadImage(url: string): Promise<HTMLImageElement> {
  return new Promise((resolve, reject) => {
    const img = new Image();
    img.src = url;
    img.onload = () => resolve(img);
    img.onerror = () => reject();
  });
}