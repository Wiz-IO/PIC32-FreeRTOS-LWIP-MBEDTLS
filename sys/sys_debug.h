#ifndef SYS_DEBUG_H
#define	SYS_DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define DEBUG    

void debug_arg(const char * frm, va_list arg);    
void debug(char * fmt, ...);
void debug_hex(char * frm, unsigned char * src, unsigned char size);

#ifdef DEBUG
#   define TRACE(_STR_, arg...)        debug( (char*) _STR_, ##arg )
#   define TRACE_HEX(_S_, _B_, _L_)    debug_hex( (char*) _S_, (uint8_t*)_B_, _L_ )
#   define TRACE_ERROR()               TRACE("[ERROR] %s() File: %s at line %d\n", __FUNCTION__, __FILE__, __LINE__)
#else
#   define TRACE(_STR_, arg...)        
#   define TRACE_HEX(_S_, _B_, _L_)  
#   define define TRACE_ERROR()
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* SYS_DEBUG_H */

