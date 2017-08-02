#ifndef __TYPES_H
#define __TYPES_H

/* Type sizes based on 64-bit linux systems */

#ifdef UNSIGNED_TYPES
typedef unsigned char       uint8_t;    /* byte */
typedef unsigned short      uint16_t;   /* 2 bytes */
typedef unsigned int        uint32_t;   /* 4 bytes */
typedef unsigned long       uint64_t;   /* 8 bytes */
#endif

#ifdef SIGNED_TYPES
typedef signed char         int8_t;
typedef signed short        int16_t;
typedef signed int          int32_t;
typedef signed long         int64_t;
#endif


#endif /* End of __TYPES_H */
