# VisCheckCS2  
**External Visibility Check for CS2 via .vpk Map Parsing (Python + C++ Module)**  

A tool to check visibility between points in CS2 without memory hacking, using `.vpk`/`.vphys` map parsing and optimized **BVH raycasting**.  

---  
## 🔹 Features  
- **Pure external approach**: No injection or `m_bSpottedByMask` dependency.  
- **Map file parsing**: Converts `.vphys` → `.opt` for fast visibility checks.  
- **Python module**: `vischeck.pyd` (C++ + pybind11) for easy integration.  
- **Performance**: ~**1ms per ray** (CPU-dependent).  

## 🔹 Repository Structure  
1. **`VPhysToOpt/`**  
   - `.vphys` → `.opt` converter (C++20).  
   - Strips junk data, keeping only **triangles and vertices**.  

2. **`VisCheck/`**  
   - Python module (`vischeck_module.cpp` + pybind11).  
   - **Möller–Trumbore** ray-triangle intersection.  

---  
## 🔹 Installation  
### 1. Compile `VPhysToOpt`  
- Open `VPhysToOpt.sln` in Visual Studio (2022 recommended).  
- Build as **Release x64** (ISO C++20).  

### 2. Compile `vischeck.pyd`  
1. Open `vischeck_module.cpp` in Visual Studio.  
2. Configure project properties:  
   - **C/C++ → General → Additional Include Directories**:  
     ```
     C:\Users\USERNAME\AppData\Local\Programs\Python\PythonXX\include;
     C:\Users\USERNAME\AppData\Local\Programs\Python\PythonXX\Lib\site-packages\pybind11\include
     ```  
   - **Linker → General → Additional Library Directories**:  
     ```
     C:\Users\USERNAME\AppData\Local\Programs\Python\PythonXX\libs
     ```  
3. Build as **Release x64**.  

### 3. Usage  
```python
import vischeck
checker = vischeck.VisCheck("de_mirage.opt")  # Load map
is_visible = checker.is_visible((x1, y1, z1), (x2, y2, z2))  # Returns bool
```
## 🔹 Notes
- **No pre-built binaries** provided (compile manually).
- **VAC-safe** if used without memory hacking.
- Map files (`.vphys`) must be extracted via **Source 2 Viewer**.
## 🔹 Credits & Links
- [License](https://github.com/Read1dno/VisCheckCS2/blob/main/LICENSE)
-  [Discord](https://discord.gg/n89PDURbTg)
[Telegram](https://t.me/bloomofficialyt)
- [UC | [Help] External visibility check](https://www.unknowncheats.me/forum/counter-strike-2-a/591548-external-visibility-check.html)
- [vasieco532 | CS2 Map Parser](https://www.unknowncheats.me/forum/counter-strike-2-a/644493-cs2-map-parser.html)
