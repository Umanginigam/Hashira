# Assignment – Safe Arithmetic Computation in C++
This assignment explores how to safely compute large mathematical expressions in C++ without running into overflow issues. Normally, when we deal with int or even long long, very large values can exceed their maximum limits and wrap around, giving completely wrong results.
To avoid this, we used long double (a floating-point type with much higher precision and range) so the program can handle large numbers and compute the result more reliably.

## 📌 **What the Program Does**
- Reads input values (for example, `a`, `b`, etc.) from a JSON file or `stdin`.  
- Performs a mathematical computation:  
  - Originally, integer overflow caused wrong results.  
  - Now, the calculation is done with **long double** so that the program can handle much larger numbers.  
- Prints the result clearly with **high precision**.
- 
## ✅ **Key Highlights**
- **Overflow-free calculations** using `long double`.  
- **Mathematical accuracy** checked against manual derivations.  
- **Readable output** (formatted with precision so you can verify values).  
- Safe compilation with **C++17 standard**.  

---

## 🚀 **How to Run**

### ▶️ Running First Case
```bash
g++ -std=c++17 main.cpp -o main
./main < inputs.json
```
### Running Second Case
```bash
g++ -std=c++17 main.cpp -o main
./main < input.json
```
<img width="728" height="236" alt="Screenshot 2025-08-22 at 10 54 57 AM" src="https://github.com/user-attachments/assets/d4b9185a-5f83-4aa4-a6eb-849833436bb9" />

### 📖 Learnings
Why integer types (int, long long) are not always safe for big computations.
How floating-point types (double, long double) can extend the range and avoid overflow.
The importance of validating program output with actual mathematical reasoning instead of just trusting code.
