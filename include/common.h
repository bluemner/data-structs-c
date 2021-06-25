#ifndef __DATA_STRUCTS_COMMON_H__
#define __DATA_STRUCTS_COMMON_H__

typedef void* pointer;
/* Print levels
 */
typedef enum print_modes
{
   PRINT_MODE_VERBOSE = 1 << 0, 
   PRINT_MODE_SUMMARY = 1 << 1 
} print_mode;

#endif
