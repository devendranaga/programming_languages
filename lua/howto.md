# Lua programming cheat sheet

## Introduction

### Installing

```bash
sudo apt install lua
```

### hello world program

`print` will print the statements on console.

A simple print statement looks as follows,

```lua
print("hello");
```

Printing a number requires a concatenation.

```lua
local a = 4
print("number is "..4)
```

The operator `..` is used for concatenation or printing.

Comments in lua are started with `--`. Multiline comments start with `--[[` and end with `--]]`.

## identifiers in Lua

| S.No | Identifier name |
|------|-----------------|
| 1 | and |
| 2 | or |
| 3 | break |
| 4 | do |
| 5 | else |
| 6 | elseif |
| 7 | end |
| 8 | in |
| 9 | repeat |
| 10 | while |
| 11 | false |
| 12 | local |
| 13 | return |
| 14 | for |
| 15 | nil |
| 16 | function |
| 17 | then |
| 18 | not |
| 19 | true |
| 20 | if |
| 21 | until |

## types

```lua
print("Hello world type : "..type("Hello world"))
print("10 is : "..type(10))
print("2.2 is : "..type(2.2))
print("true is : "..type(true))
print("nil is : "..type(nil))
```

## command line args

command line args are in global variable `arg`. To know the number of command line args, use `#arg`.

A simple way to print the command line args is as follows:

```lua
for i = 1, #arg do
    print("arg "..i.." is: "..arg[i])
end
```

## Loops

### for loops

A simple for loop iterator over strings is as follows.

```lua
names = {"john", "doe", "regan"}

for i = 1, #names do
	print(names[i])
end
```

### while loop

A simple while loop iterator over strings is as follows.

```lua
names = {"john", "doe", "regan"}

local i = 1
while (i <= #names) do
    print(names[i])
    i = i + 1
end
```

