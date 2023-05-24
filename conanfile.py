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
    license = "<Put the package license here>"
    author = "Krzysztof Obrebski krzysztof.obrebski@stonex.com"
    url = "https://bitbucket.gaincapital.com/projects/EM/repos/messaging-cms-client"
    description = "amqp cms messaging library"
    topics = ("logger")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}  
    requires = ["fmt/9.1.0@enterprise_messaging/test","spdlog/1.11.0@enterprise_messaging/test","log4cxx/0.12.1","benchmark/1.7.1"]
    generators = "cmake"
    

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
        self.copy("*.h", dst="include",src="stonex-logger-wrapper-lib\include")
        self.copy("*.lib", dst="lib",src="lib", keep_path=False)
        self.copy("*.pdb", dst="lib",src="lib", keep_path=False)
        self.copy("*.exe", dst="bin",src="bin", keep_path=False)


    def package_info(self):
        self.cpp_info.libs = self.collect_libs()