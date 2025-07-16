# ffind

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

    ffind -p [pattern] [options]

### Mandatory Arguments  
    -p, --pattern <pattern>   the pattern to search for

### Optional Arguments
    -h, --help                print the help message
    -d, --depth <default=1>   how deep into a directory you want to tranverse
    --path <default=.>        manually specify a path
    --exclusive <extension>   to search only a specify file type
    --parse                   to enable parse of files to check the pattern in the content of the files


