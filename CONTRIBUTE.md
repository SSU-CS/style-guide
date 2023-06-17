# Contributing to the SSU Style Guide

The style guide itself is written with the [mkdocs-material](https://jamstackthemes.dev/demo/theme/mkdocs-material/) theme for MkDocs.

## Development
To re-build or extend/develop the coding standards documents:

    conda create --name mkdocs-material
    conda activate mkdocs-material
    conda install pip
    pip install mkdocs-material

## Welcome to MkDocs

For full documentation visit [mkdocs.org](https://www.mkdocs.org).

## Commands

* `mkdocs new [dir-name]` - Create a new project.
* `mkdocs serve` - Start the live-reloading docs server.
* `mkdocs build` - Build the documentation site.
* `mkdocs -h` - Print help message and exit.

## Project layout

    mkdocs.yml    # The configuration file.
    docs/
        index.md  # The documentation homepage.
        ...       # Other markdown pages, images and other files.
