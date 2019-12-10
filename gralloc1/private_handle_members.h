  unsigned int size;
  unsigned int offset;
  unsigned int offset_metadata;
  uint64_t base;
  uint64_t base_metadata;
  uint64_t gpuaddr;

  unsigned int layer_count;
  uint64_t id;
  uint64_t usage;

#ifdef __cplusplus
  static const int kNumFds = 2;
  static const int kMagic = 'gmsm';

  static inline int NumInts() {
    return ((sizeof(private_handle_t) - sizeof(native_handle_t)) / sizeof(int)) - kNumFds;
  }

  private_handle_t(int fd, int meta_fd, int flags, int width, int height, int uw, int uh,
                   int format, int buf_type, unsigned int size, uint64_t usage = 0)
      : fd(fd),
        fd_metadata(meta_fd),
        magic(kMagic),
        flags(flags),
        width(width),
        height(height),
        unaligned_width(uw),
        unaligned_height(uh),
        format(format),
        buffer_type(buf_type),
        size(size),
        offset(0),
        offset_metadata(0),
        base(0),
        base_metadata(0),
        gpuaddr(0),
        layer_count(1),
        id(0),
        usage(usage) {
    version = static_cast<int>(sizeof(native_handle));
    numInts = NumInts();
    numFds = kNumFds;
  }
#endif
