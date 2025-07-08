# file-searcher

A simple command‑line tool to search for files by name, scan text files for a keyword, and report line numbers—all while respecting a configurable directory traversal depth.

## Features

- **Filename search**  
  Recursively search for files whose names match (or partially match) a given pattern.
- **Keyword parsing**  
  For each matching text file, scan its contents and print out the line numbers where a given keyword appears.
- **Depth limiting**  
  Stop traversing deeper than a specified directory depth to save time and avoid unwanted paths.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/file-searcher.git
   cd file-searcher

2. Compile
    ```bash
    make

3. Move to bin directory (Optional)
    ```bash
    mv ./ffind $HOME/.local/bin

## Usage

```bash
    ffind [pattern (required)] [depth (optional with default 1)] [path (optional with default ".")]


