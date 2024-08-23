REM compiler 16
call conan install . -s arch=x86_64 -s build_type=Debug -s compiler.runtime=MTd -s compiler.version=16  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug16  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug16 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Debug16
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug16 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Debug16 -f

call conan install . -s arch=x86_64 -s build_type=Release -s compiler.runtime=MT -s compiler.version=16  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin64Release16  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin64Release16 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Release16
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin64Release16 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Release16 -f

call conan install . -s arch=x86 -s build_type=Debug -s compiler.runtime=MTd -s compiler.version=16  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug16  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug16 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Debug16
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug16 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Debug16 -f


call conan install . -s arch=x86 -s build_type=Release -s compiler.runtime=MT -s compiler.version=16  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin32Release16  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin32Release16 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Release16
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin32Release16 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Release16 -f


REM compiler 15
call conan install . -s arch=x86_64 -s build_type=Debug -s compiler.runtime=MTd -s compiler.version=15  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug15  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug15 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Debug15
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin64Debug15 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Debug15 -f


call conan install . -s arch=x86_64 -s build_type=Release -s compiler.runtime=MT -s compiler.version=15  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin64Release15  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin64Release15 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Release15
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin64Release15 -bf ../BUILD/stonex-logger-wrapper/BuildWin64Release15 -f


call conan install . -s arch=x86 -s build_type=Debug -s compiler.runtime=MTd -s compiler.version=15  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug15  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug15 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Debug15
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin32Debug15 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Debug15 -f


call conan install . -s arch=x86 -s build_type=Release -s compiler.runtime=MT -s compiler.version=15  -s  os=Windows -s compiler="Visual Studio" -o shared=False  -if ../BUILD/stonex-logger-wrapper/BuildWin32Release15  --require-override log4cxx/0.12.1@_/_#18f63ab6a4352335291c08f8800dae78 --update --build=missing
call conan build . -if ../BUILD/stonex-logger-wrapper/BuildWin32Release15 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Release15
call conan export-pkg . enterprise_messaging/test -if ../BUILD/stonex-logger-wrapper/BuildWin32Release15 -bf ../BUILD/stonex-logger-wrapper/BuildWin32Release15 -f
REM cd ..