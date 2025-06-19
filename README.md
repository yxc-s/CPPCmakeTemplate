# A C++ Project Template Based on CMake

This repository provides a basic template for C++ projects, configured to use CMake as its build system.

## How to Compile This Project

To compile this project, please follow these steps:

1.  **Set up Vcpkg:**
    * Download Vcpkg from its official repository.
    * Add the root directory of your Vcpkg installation to your system's `PATH` environment variable. This ensures that CMake can find Vcpkg and manage your project's dependencies.

2.  **Generate Build Files:**
    Navigate to your project's root directory in your terminal or command prompt, and run the following command to generate the Visual Studio 2022 64-bit solution and project files:

    ```bash
    cmake --preset vs2022-x64
    ```

    * **Note:** This command uses a CMake preset.

        ```json
        ```

3.  **Build the Project:**
    Open the generated `.sln` file (e.g., `build/vs2022-x64/YourProjectName.sln`) in Visual Studio and build the solution (e.g., by selecting "Build Solution" from the "Build" menu, or by pressing `Ctrl+Shift+B`).

    Alternatively, you can build from the command line:

    ```bash
    cmake --build build/vs2022-x64 --config Release # Or Debug
    ```

---