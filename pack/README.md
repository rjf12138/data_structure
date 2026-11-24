# data_structure 打包说明（pm 包）

## 打包

```bash
./pack.sh        # 打包并发布到 ~/.project_manager/repo/
./pack.sh -f     # 同名同版本已存在时强制覆盖（本地迭代用）
```

产物：

- `~/.project_manager/repo/data_structure-0.1.1.pm`
- `~/.project_manager/repo/data_structure-0.1.1.pm.sha256`

包内结构：

```text
data_structure/
├── manifest.json          # lib_type = header-only
└── include/
    ├── data_struct.h
    ├── double_list.h
    ├── heap.h
    ├── queue.h
    └── skip_list.h
```

## 其它项目依赖 data_structure

```bash
pm deps add data_structure -p MyApp
```

安装后头文件位于 `extern_inc/data_structure/`，代码中按包名前缀引用：

```cpp
#include <data_structure/queue.h>
```

`pm deps list` 中该依赖的状态为 `headers-only`。

## 测试

项目自身测试依赖 `gtest@1.14.0`，需要 C++14：

```bash
pm deps install data_structure
pm build data_structure
./output/debug/bin/skip_list_test
./output/debug/bin/heap_test
./output/debug/bin/queue_test
```

## 升级版本

1. 修改 `pack/manifest.json` 与 `pack/pack.sh` 中的版本号（保持与 `.pmconfig/config.json` 一致）；
2. 执行 `./pack.sh`；
3. 使用方执行 `pm pkg install data_structure@<新版> -p MyApp`。
