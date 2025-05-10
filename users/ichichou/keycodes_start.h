#if defined(ENABLE_MTGAP) && defined(ENABLE_BUNA)
#define MT_START (QK_USER + 100)
#define BN_START (QK_USER + 200)

#elif defined(ENABLE_MTGAP)
#define MT_START (QK_USER + 100)

#elif defined(ENABLE_BUNA)
#define BN_START (QK_USER + 100)

#endif
