## Syntax
* The syntax of function template is
```c++
template <class identifier> function declaration;
```

  * The `template` is a keyword that is used to define the template.
  * The `class identifier` is a placeholder that can be used to accept any datatype.
  * The `function declaration` is the function code that is used to work with the generic data type.


* The syntax of class template is
```c++
template <class datatype>
class definition
```

`typename` and `class` are interchangeable in the declaration of a type template parameter. however, have to use `class` (and not `typename`) when declaring a template template parameter

## Function template
Return the greater one of 2 numbers
```c++
Template <class myType>
myType getMax(myType a, myType b){
    return(a > b ? a : b);
}
```
You don't need to specify the type of 2 numbers, whether the caparison is between the 2 float or 2 integers.
Because we create a template function with `myType` as its template argument. This template arguments represent a type that yet has been specified, but that can be used in the template function as if it were a regular type.



## How CPP CTAD works
[How class template argument deduction works?](https://youtu.be/STJExxBU54M)

```c++
// C+98:
std::pair<std::string, int> p1("THX", 1138);

// C+11:
auto p2 = std::make_pair("THX", 1138);
// deduces std::pair<const char*, int>

// C++14:
using name space std::literals::string_literals;
auto p3 = std::make_pair("THX"s, 1138);
//deduces std::make_pair<std::string, int>

// C+17
std::pair p4{"THX"s, int};
// deduces std::pair<std::string, int>
```

I think it's pretty cool, when a pattern was discovered, and a mode was proved to be right, then it applied in every possible relevant area. We now have templating language in `Django`, and `Sphinx`. So every precedent other descendent programming languages.

> A templating language basically is a language which allows defining placeholders that should later on be replaced for the purpose of implementing designs. Obviously modern template languages not only support placeholders, but also loops and conditions which are often necessary for designing a web page. Some even support more advanced but still useful techniques like template inheritance, macros and sandboxing.