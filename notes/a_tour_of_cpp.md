# A Tour of C++

## 1. The Basics

- Programs
  - source file -> (compiler) -> object file -> (linker) -> executable
  - C++: staticly typed language.

- main()
  - entry point
  - non zero return is failure
    
- scope
  - global
  - local
  - member
  - namespace
  - dynamic storage (heap) `new`
    - `auto card = new Card();`
    - deleted by `delete`

- Pointer, array, references
  - auto
    - `for (auto val : val_array)`
    - `for (auto val : {1, 2, 3})`
  - auto thoruugh reference
    - `for (auto &val : val_array)`

## 2. Structures
- Member initializer
  - `Class_name (int s) : member1_name {member1_new_val}, member2_name {member2_new_val} {}`

- enum class
  - `enum class Stage { one_one, one_two, one_three };`
