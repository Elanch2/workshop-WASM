# Van C naar WebAssembly Workshop

Leer hoe je C‑code compileert naar WebAssembly en deze in de browser uitvoert.

## 🧭 Doelstellingen
- Begrijp de basisconcepten van WebAssembly  
- Gebruik **Emscripten** om C te compileren naar `.wasm`  
- Roep WebAssembly‑functies aan vanuit JavaScript  
- Beheer geheugen en wissel tekst (strings) tussen C en JavaScript uit  

## 🧰 Vereisten
Installeer vooraf:

```bash
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk && ./emsdk install latest && ./emsdk activate latest
source ./emsdk_env.sh
```

Controleer of alles werkt:
```bash
emcc -v
```

## 🧩 Oefeningen
Elke stap bevindt zich in de map `/exercises`.

1. **Hello C** – compileer en voer een eenvoudig programma uit  
2. **Add Function** – exporteer een C‑functie naar JavaScript  
3. **Reverse String** – verwerk tekst in WebAssembly‑geheugen  

Volg de aanwijzingen in de opmerkingen binnen elk bestand.

## 🔧 Bouwen en Uitvoeren
```bash
emcc source.c -o output.html
emrun --no_browser --port 8080 .
```

Open vervolgens `http://localhost:8080/output.html` in je browser.

## 🧪 Mini‑projectidee
Combineer als laatste stap je functies tot een klein browsertooltje  
(bijv. een tekstomkeerder of een rekenmachine).

## 📚 Verdere Lectuur
- https://emscripten.org/docs/  
- https://developer.mozilla.org/docs/WebAssembly  

---
© IT‑Tools‑2 Workshop 2025
