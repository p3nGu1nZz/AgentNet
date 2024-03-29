# AgentNet

AgentNet is a sophisticated peer-to-peer networking framework that empowers distributed agents to communicate and share data with high efficiency. Leveraging Vulkan for graphics rendering, AgentNet is built for performance and scalability, providing a robust platform for decentralized agent interactions.

## Getting Started

These instructions will guide you through getting a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

Before you begin, ensure you have the following installed:
- Vulkan SDK
- CMake
- A C++ compiler like GCC or Clang
- Access to Llama sources (see below)

### Llama Sources

To build this project from source, you will need access to the Llama sources. Follow these steps to download them:
1. Visit the Llama GitHub repository and follow the instructions to register and accept the license¹.
2. Once approved, you will receive a custom URL via email from Meta.
3. Clone the Llama repository and run the `download.sh` script with the custom URL provided. (Requires Linux or MacOS)

### Installation

Follow these steps to set up your development environment:

1. Clone the repository:
```bash
git clone https://github.com/K-Rawson/AgentNet.git
```

2. Navigate to the project directory:
```bash
cd AgentNet
```

3. Create a build directory:
```bash
mkdir build && cd build
```

4. Run CMake to configure the project:
```bash
cmake ..
```

5. Build the project:
```bash
cmake --build .
```

## Running the Tests

To run the automated tests for this system, use the following command:

```bash
ctest
```

## Deployment

For deployment, additional steps may be required, such as setting up a server environment or configuring network settings.

## Built With

* [Vulkan](https://www.vulkan.org/) - A low-overhead, cross-platform 3D graphics and compute API.
* [CMake](https://cmake.org/) - An open-source, cross-platform family of tools designed to build, test, and package software.
* [Llama](https://llama.meta.com/llama-downloads/) - For building AgentNet llama models from source. (Advanced)

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/K-Rawson/AgentNet/tags).

## Authors

* **K-Rawson** - *Initial work* - [AgentNet](https://github.com/K-Rawson/AgentNet)

See also the list of [contributors](https://github.com/K-Rawson/AgentNet/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

* Tonic-AI

Please cite this project as:

```
Rawson, K. (2024). AgentNet: An Innovative AI Framework for Gaming. [https://github.com/K-Rawson/AgentNet](https://github.com/K-Rawson/AgentNet)
```
