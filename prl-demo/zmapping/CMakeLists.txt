# 查找当前目录下所有源文件
# 名称保存到 DIR_LIB_SRCS 
aux_source_directory(. DIR_LIB_SRCS)
# 生成链接库
add_library (zmapping_lib ${DIR_LIB_SRCS})
