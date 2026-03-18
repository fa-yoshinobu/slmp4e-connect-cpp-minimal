@echo off
echo [DOCS] Building SLMP C++ Docs with Doxygen...
doxygen Doxyfile
if %errorlevel% neq 0 (
    echo [ERROR] Doxygen not found or failed. Please install doxygen to use this script.
)
echo [SUCCESS] Docs (if generated) at %cd%\publish\docs\index.html
pause

