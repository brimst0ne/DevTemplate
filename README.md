# DevTemplate
Template repository for study projects.
* Build system: cmake
* Tests: gtest
* Code style check: cpplint

## Merging an upstream repository into your fork (master branch)
```
 git checkout master
 git pull https://github.com/UsovaMA/Development-Template.git master
```
## Update working branch
```
 git checkout <your branch>
 git rebase master
```
## Build project with cmake
cmake -G "Visual Studio 15 2019"  (check the year of your Visual Studio version, it may vary)
