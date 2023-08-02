from conans import ConanFile, CMake, tools


class EnjinPlatformSDK(ConanFile):
    settings = "os", "compiler", "arch", "build_type"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()
        if tools.get_env("CONAN_RUN_TESTS", True):
            cmake.test()

    def requirements(self):
        self.requires("gtest/1.13.0")
        self.requires("rapidjson/1.1.0")
        self.requires("cpp-httplib/0.11.3")
        self.options["cpp-httplib"].with_openssl = True
        self.requires("ixwebsocket/11.4.3")

        if self.settings.compiler == "gcc" or self.settings.compiler == "clang":
            self.requires("date/3.0.1")
