# clogging

Clogging is a (very) simple c++ logging class.

  - 8 verbosity levels
  - Optional JSON output
  - Very simple usage
  - Optional Windows.h for VS OutputDebugString usage

I needed a very simple and quick logging class for my university and personal projects. The ones already on github do way more than what I need, so I've made my own.

### Verbosity levels

| Verbosity enum | Verbosity |
| ------ | ------ |
| DEBUG | Debug |
| INFO | Information |
| NOTICE | Notice |
| WARN | Warning |
| ERR | Error |
| CRIT | Critical |
| ALERT | Alert |
| EMERG | Emergency |

# Installation

Installation is very simple, copy the files into your project dir and include "Logger.h". There is a JSON dependency, however. So for those functionalities include your favorite JSON lib. The one I used here is [JSON for modern C++](https://github.com/nlohmann/json).

``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
}
```

### Default behaviour and output
If no other arguments are passed to CLOG, it will default to verbose DEBUG and to the default output type (non- JSON). 
``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
	
	string msg = "hello world!";
	CLOG(msg);
}
```

The code above would produce an output like that:

```
[Sat Feb 17 19:43:53 2018] [DEBUG] hello world!
```

You can also set a custom file location by adding another argument to ADD_FILE:

``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log", "C:\\my_dir\\");
	
	string msg = "hello world!";
	CLOG(msg);
}
```

### Verbosity CLOG parameters

Add the desired verbosity level with *Verbosity::INFO*.

``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
	
	string msg = "hello world!";
	CLOG(msg, Verbosity::INFO);
}
```
The code above would produce an output like this:

```
[Sat Feb 17 19:43:53 2018] [INFO] hello world!
```

### Output customization of CLOG arguments
As mentioned above, without including the output type, CLOG will default to normal output format, but you can also set that if you wish to see from the code what type is being outputted. This produces the same output as the example above.

``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
	
	string msg = "hello world!";
	CLOG(msg, Verbosity::INFO, Output::DEFAULT);
}
```
The code above would produce an output like this:
```
[Sat Feb 17 19:43:53 2018] [INFO] hello world!
```

To use the JSON output format, add change the 3rd argument to *Output::JSON*.

``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
	
	string msg = "hello world!";
	CLOG(msg, Verbosity::INFO, Output::JSON);
}
```
The code above would produce an output like this:
```
{"output_message":"hello world!","timestamp":"Sat Feb 17 19:47:23 2018","verbosity":"INFO"}
```

There is a possibility to produce both the default and the JSON output format and the same time:
``` c++
#include "Logger.h"

int main() {

	INIT_CLOGGING;
	ADD_FILE("clogging.log");
	
	string msg = "hello world!";
	CLOG(msg, Verbosity::WARN, Output::BOTH);
}
```
The code above would produce an output like this, (in new lines)
```
[Sat Feb 17 19:52:54 2018] [WARNING] hello world!
{"output_message":"hello world!","timestamp":"Sat Feb 17 19:52:54 2018","verbosity":"WARNING"}
```

# Using Visual Studio OutputDebugStrings
Now there is a possibility to use OutputDebugStrings in Visual Studio. All you have to do is define the macro CLOG_USE_VS. You will have to do this in "Logger.h", but there is a dedicated space at the beggining of the file for these macros.

```c++
// Uncomment any of these macros for more logging and debugging options.
	// To use Windows.h and OutputDebugString in any Visual Studio version.
#define CLOG_USE_VS 1 
//------------
```

### Writing into VS Debug
It is simple to write into the Debug console, all you have to do is:

```c++
string msg = "hello world!";
//Takes three arguments
CLOG_VS(msg, Verbosity::EMERG, Output_vs::TO_FILE_BOTH);
```
You have the option to either write into the Debug console, or write into Debug and the file (in default format), or write into the Debug console and into the file both as default and JSON format. You can choose to only include your massage. The default output will look like this in the Debug console:

```c++
[Sun Feb 18 20:48:44 2018] [EMERGENCY] hello world!
```

### Todos

 - Custom verbosity levels
 - Timer
 - Custom time to keep the logs
 - Custom JSON object depth
 - VS OutputDebugString colors?
 - Conditional logging

License
----

MIT
