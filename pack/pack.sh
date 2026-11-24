#!/bin/bash
# 将 data_structure 头文件打包成 .pm 并发布到本地仓库
#
# 用法:
#   ./pack.sh            # 打包并发布
#   ./pack.sh -f         # 同名同版本已存在时强制覆盖
#
# 产物:
#   ~/.project_manager/repo/data_structure-<version>.pm (+ .sha256)
#
# 包内结构:
#   data_structure/
#   ├── manifest.json
#   └── include/*.h
set -e

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PKG_NAME="data_structure"
PKG_VERSION="0.1.2"
WORK_DIR="$ROOT/pack/build"
PKG_DIR="$WORK_DIR/$PKG_NAME"

FORCE_FLAG=""
if [ "$1" = "-f" ]; then
    FORCE_FLAG="-f"
fi

echo "==> 清理旧的打包产物"
rm -rf "$PKG_DIR"
mkdir -p "$PKG_DIR/include"

echo "==> 拷贝头文件与 manifest"
cp "$ROOT"/inc/*.h "$PKG_DIR/include/"
cp "$ROOT/pack/manifest.json" "$PKG_DIR/"

echo "==> 打包并发布到本地仓库"
pm pkg create "$PKG_DIR" $FORCE_FLAG

echo "==> 完成, 仓库内容:"
pm pkg list | grep -E "$PKG_NAME|name" || true
