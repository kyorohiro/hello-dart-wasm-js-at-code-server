import 'dart:js' as js;
import 'dart:typed_data';


js.JsObject Module = js.context["Module"];
js.JsFunction hello =  Module.callMethod('cwrap',['hello']);
js.JsFunction sum =  Module.callMethod('cwrap',['sum','number',["number", "number"]]);
js.JsFunction sum_double =  Module.callMethod('cwrap',['sum_double','number',["number", "number"]]);

js.JsFunction new_buffer =  Module.callMethod('cwrap',['create_buffer','number',["number"]]);
js.JsFunction destroy_buffer =  Module.callMethod('cwrap',['create_buffer','number',["number"]]);
js.JsFunction get_buffer = js.context["get_buffer"];// from util.js
js.JsFunction free_buffer =  Module.callMethod('cwrap',['destroy_buffer','void',["number"]]);
// void destroy_buffer(uint8_t* p)

// https://developers.google.com/web/updates/2018/03/emscripting-a-c-library
//https://stackoverflow.com/questions/13908281/passing-typed-array-buffer-to-javascript-from-dart-with-js-interop#13933594
void main() {
  print("--hello");
  hello.apply([]);
  print("--");
  print("--sum");
  int r = sum.apply([1,2]);
  print(r);
  print("--");
  print("--sum_double");
  r = sum_double.apply([1,2]);
  print(r);
  print("--");
  print("--create_buffer");
  int pointer = new_buffer.apply([10]);  
  var heap8 = Module["HEAP8"];
  //js.JsObject uint8Array = js.context["Uint8Array"];
  //var bufView = new js.JsObject(uint8Array, [pointer, 10]);
  Uint8List buffer = get_buffer.apply([pointer, 10]);
  //var uhaep = Uint8List.view(heap8, pointer, 10);
  buffer[0] = 1;
  print("${heap8[pointer]}");
  print("--");
  print("--free_buffer");
  free_buffer.apply([pointer]);
  print("--");
  //rint(r);

}
