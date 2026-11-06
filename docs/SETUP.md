# Destiny3DEngine — Doxygen & GitHub Pages

## Local Doxygen

Install [Doxygen](https://www.doxygen.nl/download.html) and optionally [Graphviz](https://graphviz.org/download/). Run from the root of the Git repository:

```powershell
doxygen Doxyfile
```

Open `build/doxygen/html/index.html`. Only the engine headers and source files are indexed; third-party DirectXTK code is excluded.

## Publish to GitHub Pages

1. Copy the five provided files into the `engineImplementation` branch, preserving their relative paths.
2. Commit and push them.
3. In GitHub, go to **Settings → Pages → Build and deployment → Source → GitHub Actions**.
4. Go to **Actions → Publish website and Doxygen API → Run workflow**, choose `engineImplementation` and run it.
5. After successful deployment, open:
   - `https://g-herrera.github.io/Destiny3DEngine/`
   - `https://g-herrera.github.io/Destiny3DEngine/api/`

Further commits affecting the engine, documentation, or website on `engineImplementation` will trigger publishing.

**Important:** The landing graphic is illustrative and not a live Direct3D demonstration. A GitHub Pages website cannot run a native Windows Direct3D application.

## Documenting APIs

Use Doxygen comments (`/** ... */`) on public C++ declarations. `EXTRACT_ALL = YES` makes undocumented declarations visible while the project evolves.
