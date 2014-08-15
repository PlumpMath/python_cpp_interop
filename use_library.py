import messages_pb2
import ctypes
from ctypes import *

native_library = ctypes.CDLL('native_library.dll')

request = messages_pb2.Request()
for i in range(10):
  request.value.append(i)

request_blob = request.SerializeToString()
request_blob_p = ctypes.create_string_buffer(request_blob)

response_length = native_library.CalculateSquareRoot(len(request_blob), request_blob_p)
response_blob = ctypes.create_string_buffer(response_length)
native_library.RetrieveResult(response_blob)
response = messages_pb2.Response()
response.ParseFromString(response_blob)

for i in range(10):
  print str(response.value[i])