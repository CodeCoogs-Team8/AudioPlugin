# Team 8 Audio Development


Let's Create an Audio Plugin (e.g., a VST3 plugin) with C++!

Heard about the [JUCE C++ framework](https://github.com/juce-framework/JUCE) but not sure how to start a JUCE project?

Well here is the templae to get started on development for our Team!

In this repository we have 

* C++ 23 standard
* effortless handling of third-party dependencies with the CPM package manager; use the C++ libraries you want together with JUCE
* highest warning level and "treat warnings as errors"
* ready-to-go unit test project with GoogleTest

Additionally we have 

* continuous integration made easy with Github actions: build and run tests on the main branch and on every pull request
* automatic clang-format on C++ files run on every commit; don't worry about code formatting anymore!

## Usage


After cloning it locally, you can proceed with the usual CMake workflow.

In the main repo directory execute

```bash
$ cmake -S . -B build
$ cmake --build build
```

The first run will take the most time because the dependencies (CPM, JUCE, and googletest) need to be downloaded.

Alternatively, you can use bundled CMake presets:

```bash
$ cmake --preset default # uses the Ninja build system
$ cmake --build build
$ ctest --preset default
```

Existing presets are `default`, `release`, and `Xcode`.

To run clang-format on every commit, in the main directory execute

```bash
pre-commit install
```

(for this you may need to install `pre-commit` with `pip`: `pip install pre-commit`).

Later on we can change the audio pluging project name later down the line!

