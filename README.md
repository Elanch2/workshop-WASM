# 🦀 Van C naar WebAssembly – IT Tools 2 Workshop

**Duur:** 2 uur  
**Niveau:** Beginner → Gemiddeld  
**Doel:** Begrijp en ervaar de kracht van WebAssembly via C.

---

## 📋 Leerdoelen
- Compileer C‑code naar WebAssembly (Wasm)  
- Voer `.wasm` uit en communiceer ermee vanuit JavaScript  
- **Vergelijk prestaties van Wasm vs JavaScript**  
- Verwerk tekst en beheer geheugenuitwisseling tussen JS en C  

---

## 🧰 Vereisten
Installeer dit vooraf:

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

Controleer met:
```bash
emcc -v
```

---

## 🧩 Overzicht van oefeningen
| Map | Beschrijving |
|------|---------------|
| 01_hello_c | Compileer & voer je eerste C‑code uit in de browser |
| 02_add_function | Exporteer & roep een gecompileerde C‑functie aan vanuit JS |
| 03_js_vs_wasm_benchmark | Vergelijk de snelheid van JavaScript en WebAssembly |
| 04_reverse_string | Manipuleer strings met lineair geheugen |

Volg de stappen één voor één en let op de uitvoer in de terminal en browser.

---

## 🧪 Benchmark‑doel
Deelnemers meten de uitvoeringstijd van een grote berekening, zowel in JS als in gecompileerde C (Wasm).  
We gebruiken `performance.now()` om de tijden te vergelijken.

---

## 🔧 Uitvoerinstructies
```bash
emcc file.c -o file.html
emrun --no_browser --port 8080 .
# of open file.html direct in de browser
```

---

## 🚀 Na de Workshop
- Experimenteer met optimalisatie‑vlaggen zoals `-O3` of `-Oz`  
- Ontdek Rust → Wasm  
- Probeer WASI voor uitvoering buiten de browser  

---

© IT‑Tools‑2 Workshop 2025
