A library for Dart developers.

Created from templates made available by Stagehand under a BSD-style
[license](https://github.com/dart-lang/stagehand/blob/master/LICENSE).

## Usage

A simple usage example:

```dart
import 'package:app/app.dart';

main() {
  var awesome = new Awesome();
}
```

## Features and bugs

Please file feature requests and bugs at the [issue tracker][tracker].

[tracker]: http://example.com/issues/replaceme

emcc -s EXPORTED_FUNCTIONS="['_hello']" -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' hello.c -o hello.js

emcc -s EXPORTED_FUNCTIONS="['_hello','_sum','_create_buffer','_destroy_buffer','_sum_double']" -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' hello.c -o hello.js
cp hello.wasm ../web/hello.wasm 
cp hello.js ../web/hello.js