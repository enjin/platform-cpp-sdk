# Enjin Platform SDK by Enjin for C++

[![License: LGPL 3.0](https://img.shields.io/badge/license-LGPL_3.0-purple)](https://opensource.org/license/lgpl-3-0/)
[![Build & Test](https://github.com/enjin/platform-cpp-sdk/actions/workflows/Build%20&%20Test.yml/badge.svg?branch=master)](https://github.com/enjin/platform-cpp-sdk/actions/workflows/Build%20&%20Test.yml)

Open source SDK for connecting to and interacting with the Platform.

More documentation may be found on the [Official Documentation Page](https://docs.enjin.io/).

## Packages

## Compatibility

The Enjin Platform C++ SDK is a C++20 shared-library and is developed with cross-platform usage in mind. Platform and
compiler combinations tested are as follows:

* GCC 11.3.0 on Linux-Ubuntu (64-bit)
* Clang 14.0.0 on Linux-Ubuntu (64-bit)
* MSVC 2022 version 17.0 on Windows 10 (64-bit)

## Installation

The following dependencies are used for building the SDK:

* [CMake (3.16+)](https://cmake.org/) as a build tool

The following libraries are used by the SDK for some of its functionality and must be locatable by CMake's
`find_package()` function, however these libraries are not necessary to link to your own target to use this SDK:

* [RapidJSON (1.1.0+)](https://github.com/Tencent/rapidjson) for processing JSON
* [date (3.0.1+)](https://github.com/HowardHinnant/date) (non-MSVC) for processing ISO 8601 dates
* [cpp-httplib (0.11.3+)](https://github.com/yhirose/cpp-httplib) for the HTTP client
    * [openssl (3.0.8+)](https://github.com/openssl/openssl) for HTTPS support
* [IXWebSocket (11.4.3+)](https://github.com/machinezone/IXWebSocket) for the websocket client

To utilize this SDK you may clone it into your project tree with:

```console
$ git clone https://github.com/enjin/platform-cpp-sdk.git
```

Then use the following in your project's CMakeLists file:

```cmake
add_subdirectory(platform-cpp-sdk)
target_link_libraries(my_target PRIVATE EnjinPlatformSdk::Core)
```

To use supplemental packages, such as the Beam package, the CMake project for this SDK will need to be loaded with the
necessary options. These options are:

* `ENJINSDK_INCLUDE_BEAM`
* `ENJINSDK_INCLUDE_FUEL_TANKS`
* `ENJINSDK_INCLUDE_MARKETPLACE`

Once toggled **on** the packages may be linked as needed:

```cmake
target_link_libraries(my_target PRIVATE
        EnjinPlatformSdk::Beam
        EnjinPlatformSdk::FuelTanks
        EnjinPlatformSdk::Marketplace)
```

#### Linux

Alternatively, on Linux you may include the SDK in your project by cloning and building it with the following commands:

```console
$ git clone https://github.com/enjin/platform-cpp-sdk.git
$ cmake ./platform-cpp-sdk [options] && make -j -C ./platform-cpp-sdk
```

From here, you may use CMake's `find_package()` function to find `EnjinPlatformSdk` and link the library,
`EnjinPlatformSdk::Core` to your target as well as any of the packages supporting different schemas.

## Changelog

Please see [CHANGELOG](https://github.com/enjin/platform-csharp-sdk/blob/master/CHANGELOG.md) for more information on
recent changes.

## Contributing

Please see [CONTRIBUTING](https://github.com/enjin/platform-csharp-sdk/blob/master/CONTRIBUTING.md) for details.

## Credits

* [Enjin](https://enjin.io)
* [All Contributors](https://github.com/enjin/platform-csharp-sdk/contributors)

## License

This project is licensed under the LGPL 3.0 License. Please
see [LICENSE](https://github.com/enjin/platform-csharp-sdk/blob/master/LICENSE) for more information.
