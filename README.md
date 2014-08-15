python_cpp_interop
==================

This project gives a simple example of calling C++ code from Python.
The basic idea is to use ctypes module in Python to call an library with plain 'C' interface,
and to use Google Protocol Buffers to pass complex data structures between Python and C++.

This example is made for Windows users, but the same technique works very well on Linux and on other platforms.

Steps to run this example
=========================

1. Install Python 2.7, 32 bits.

2. Download and unpack https://protobuf.googlecode.com/files/protobuf-2.5.0.tar.gz

3. Download and unpack protoc.exe from https://protobuf.googlecode.com/files/protoc-2.5.0-win32.zip

4. Follow Windows-specific part of the instructions in protobuf-2.5.0\python\README.txt.
   Essentially you have to run the following steps:

         python setup.py build
      
         python setup.py install
      
         python setup.py test

    This compile and installs protobuf module so that you can use it later from your Python scripts.
    Note that protoc.exe has to be placed under protobuf-2.5.0\python, because it is used by setup.py script.

5. Run the 'use_library.py' script

         python use_library.py

   This script uses native_library.dll to calculate square root of some numbers.
   Google protocol buffers are used to pass the numbers into the library.
   
   Note that the native_library.dll is compiled as 32 bits, and 64-bit Python will refuse to load it.
   To run this example make sure to use 32 bit Python.


Steps to recompile 'native_library.dll'
=======================================

Use Visual Studio 2012 to compile native_library/native_library.sln.
This will produce native_library.dll. Replace this file in the root of this
distributive so that it gets picked up by use_library.py script.

If you use different version of Visual Studio, then you have to recompile projects 
under protobuf-2.5.0\vsprojects\ to produce appropriate static library
(libprotobuf.lib).


Steps to recompile 'messages.proto'
===================================

1. Download and unpack https://protobuf.googlecode.com/files/protoc-2.5.0-win32.zip
2. Run the following command from cmd (windows command prompt)

         protoc.exe --cpp_out=native_library --python_out=. messages.proto

The resulting files are native_library/messages.pb.h, native_library/messages.pb.cc, and messages_pb2.py.
