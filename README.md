# From C to WebAssembly Workshop

Learn how to compile C code into WebAssembly and run it in the browser.

## 🧭 Objectives
- Understand basic WebAssembly concepts
- Use **Emscripten** to compile C into `.wasm`
- Call WebAssembly functions from JavaScript
- Manage memory and exchange strings

## 🧰 Prerequisites
Install ahead of time:

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk && ./emsdk install latest && ./emsdk activate latest
source ./emsdk_env.sh
```

Check:
```bash
emcc -v
```

## 🧩 Exercises
Each step is inside the `/exercises` folder.

1. **Hello C** – compile and run a simple program  
2. **Add Function** – export a C function to JS  
3. **Reverse String** – handle text in WebAssembly memory  

Follow the comments in each file.

## 🔧 Build & Run
```bash
emcc source.c -o output.html
emrun --no_browser --port 8080 .
```

Then open `http://localhost:8080/output.html`.

## 🧪 Mini‑Project Idea
As a final step, combine your functions into a small browser tool
(e.g. string reverser, calculator).

## 📚 Further Reading
- https://emscripten.org/docs/
- https://developer.mozilla.org/docs/WebAssembly

---
© IT‑Tools‑2 Workshop 2025
