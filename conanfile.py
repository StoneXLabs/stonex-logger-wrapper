from conans import ConanFile, CMake, tools

def get_verion_tag():
    git = tools.Git("stonex-logger-wrapper")
    try:
        return "%s" % (git.get_tag())
    except Exception as e:
        return e

class StonexLogger(ConanFile):
    name = "stonex-logger-wrapper"
    version = get_verion_tag()
    license = "Apache License 2.0"
    author = "Krzysztof Obrebski krzysztof.obrebski@stonex.com"
    url = "https://github.com/StoneXLabs/stonex-logger-wrapper.git"
    description = "stonex logger wrapper"
    topics = ("logger", "spdlog", "log4cxx")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}  
    generators = "cmake"

    def configure(self):
        self.options["fmt"].shared = self.options.shared
        self.options["spdlog"].shared = self.options.shared
        self.options["log4cxx"].shared = self.options.shared

    def requirements(self):
        if self.settings.os == "Linux":
           self.requires("fmt/9.1.0")
           self.requires("spdlog/1.11.0")
        else:
            self.requires("fmt/9.1.0@enterprise_messaging/test")
            self.requires("spdlog/1.11.0@enterprise_messaging/test")
        self.requires("log4cxx/0.12.1")    
    
    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC


    def source(self):
        pass
        

    def build(self):
        cmake = CMake(self)
        cmake.definitions["CONAN_BUILD"] = "ON"
        cmake.definitions["BUILD_TEST"] = "ON"
        cmake.configure()
        cmake.verbose = True
        cmake.build()
		
          
 #       print("##teamcity[setParameter name='{}' value='{}']".format(self.name,self.version))


    def package(self):
        self.copy("*.h", dst="include",src="stonex-logger-wrapper-lib/include")
        self.copy("*.lib", dst="lib",src="lib", keep_path=False)
        self.copy("*.a", dst="lib",src="lib", keep_path=False)
        self.copy("*.so", dst="lib",src="lib", keep_path=False)
        self.copy("*.pdb", dst="lib",src="lib", keep_path=False)
        self.copy("*.exe", dst="bin",src="bin", keep_path=False)


    def package_info(self):
        self.cpp_info.libs = self.collect_libs()
