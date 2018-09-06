/*
		FileName: common.h
*/
/*
    plib_mz for PIC32MZ microcontrollers - Copyright (C) 2016
                                            Spas Spasov.

    This file is part of plib_mz.

    "plib_mz" is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    "plib_mz" is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
   Concepts and parts of this file have been contributed by Spas Spasov.
 */

#ifndef COMMON_H
#define	COMMON_H

#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <sys/kmem.h>

#ifdef	__cplusplus
extern "C" {
#endif

// *****************************************************************************
// *****************************************************************************
// Section: Data Types
// *****************************************************************************
// *****************************************************************************
/* These macros are used to access bits in registers in the peripheral libraries
*/

// *****************************************************************************
/* SFR_TYPE datatype

  Summary:
    Defines the type for SFR on the 32 bit parts

  Description:
    This type is specific to the SFR type in the 32 bit parts.

*/

typedef volatile uint32_t SFR_TYPE;


// *****************************************************************************
/* SFR_DATA datatype

  Summary:
    Defines the type for SFR data on the 32 bit parts

  Description:
    This type is specific to the SFR data in the 32 bit parts.

*/

typedef uint32_t SFR_DATA;


// *****************************************************************************
/* PIC32MZ kseg2/3 to physical address conversion macros

  Summary:
    Macros to convert between kseg2/3 virtual and physical addresses

  Description:
    Macros to convert between kseg2/3 virtual and physical addresses. Needed for
    DMA transfer to/from external memory on EBI or SQI with PIC32MZ.

*/
#define KVA2_TO_PA(v) (((v) & 0x3FFFFFFF) | 0x20000000)
#define KVA3_TO_PA(v) ((v) & 0x3FFFFFFF)
#define PA_TO_KVA2(v) (((v) & 0xDFFFFFFF) | 0xC0000000) 
#define PA_TO_KVA3(v) ((v) | 0xC0000000) 


//*****************************************************************************
/* Flash Error Correcting Code (ECC) Configuration enumeration

  Summary:
    Selects how ECC is applied to Flash memory.

  Description:
    This enumeration selects how ECC is applied to Flash memory.

  Remarks:
    None.
*/
typedef enum {

    // ECC and dynamic ECC are disabled
    DEVCON_ECC_DISABLED        /*DOM-IGNORE-BEGIN*/ = 3 /*DOM-IGNORE-END*/,

    // ECC and dynamic ECC are disabled and the configuration locked
    DEVCON_ECC_DISABLED_LOCKED /*DOM-IGNORE-BEGIN*/ = 2 /*DOM-IGNORE-END*/,

    // Dynamic Flash ECC is enabled and the configuration is locked
    DEVCON_DYN_ECC_ENABLED_LOCKED  /*DOM-IGNORE-BEGIN*/ = 1 /*DOM-IGNORE-END*/,

    // Flash ECC is enabled, the configuration is locked, word Flash writes disabled
    DEVCON_FLASH_ECC_ENABLED_LOCKED  /*DOM-IGNORE-BEGIN*/ = 0 /*DOM-IGNORE-END*/

} DEVCON_ECC_CONFIG;



// *****************************************************************************
/* Function:
    unsigned uintptr_t _PLIB_VirtToPhys ( const void* p )

  Summary:
    Translates a virtual pointer to a physical address

  Description:
    This function translates a virtual pointer to a physical address suitable
    for use with DMA and other hardware operations that require a physical
    address.

  Precondition:
    None.

  Parameters:
    p       - Pointer to be converted

  Returns:
    The physical address corresponding to the virtual input pointer.

  Example:
    <code>
    int         myData;
    uintptr_t   physAddr;
    physAddr = _PLIB_VirtToPhys(&myData);  // Safe to write to DMA register
    </code>

  Remarks:
    On parts that do not require this translation, this function returns
    the given address unchanged (other than by the data type to which
    it is cast).
*/
#ifndef _PLIB_VirtToPhys
extern __inline__ uintptr_t __attribute__ ( ( always_inline ) ) _PLIB_VirtToPhys_Default ( const void* p )
{
     return ( (((uintptr_t)(p))&0x80000000L) ? (((uintptr_t)(p))&0x1fffffffL) : (((uintptr_t)(p))|0x40000000L) );
}
#define _PLIB_VirtToPhys    _PLIB_VirtToPhys_Default
#endif

// *****************************************************************************
/* Function:
   void* _PLIB_PhysToVirtK0 ( uintptr_t a )

  Summary:
    Translates a PIC32 K0 segment physical address to a virtual pointer

  Description:
    This function translates a PIC32 K0 segment physical address to a virtual
    pointer.

  Precondition:
    None.

  Parameters:
    a       - Physical address to be converted

  Returns:
    A virtual pointer corresponding to the given physical address.

  Example:
    <code>
    char *      pMyData;    // Virtual pointer to DMA data
    pMyData = _PLIB_PhysToVirtK0(PHY_ADDR_MY_DMA_BUFFER);
    </code>

  Remarks:
    On parts that do not require this translation, this function returns
    the given address unchanged (other than by the data type to which
    it is cast).
*/
#ifndef _PLIB_PhysToVirtK0
extern __inline__ void* __attribute__ ( ( always_inline ) ) _PLIB_PhysToVirtK0_Default ( uintptr_t a )
{
	return ( ( a<0x40000000L )?( void* )( a|0x80000000L ):( void* )( a-0x40000000L ) );
}
#define _PLIB_PhysToVirtK0  _PLIB_PhysToVirtK0_Default
#endif

// *****************************************************************************
/* Function:
   void* _PLIB_PhysToVirtK1 ( uintptr_t a )

  Summary:
    Translates a K1 segment physical address to a virtual pointer

  Description:
    This function translates a K1 segment physical address to a virtual
    pointer.

  Precondition:
    None.

  Parameters:
    a       - Physical address to be converted

  Returns:
    A virtual pointer corresponding to the given physical address.

  Example:
    <code>
    char *      pMyData;    // Virtual pointer to DMA data
    pMyData = _PLIB_PhysToVirtK1(PHY_ADDR_MY_DMA_BUFFER);
    </code>

  Remarks:
    On parts that do not require this translation, this function returns
    the given address unchanged (other than by the data type to which
    it is cast).
*/
#ifndef _PLIB_PhysToVirtK1
extern __inline__ void* __attribute__((always_inline)) _PLIB_PhysToVirtK1_Default( uintptr_t a )
{
	return (a<0x40000000L?(void*)(a|0xa0000000L):(void*)(a-0x40000000L));
}
#define _PLIB_PhysToVirtK1  _PLIB_PhysToVirtK1_Default
#endif

// *****************************************************************************
// *****************************************************************************
// Section: 32-bit specific macros
// *****************************************************************************
// *****************************************************************************
/*  This section contains macros that utilize the CLR/SET/INV shadow registers
 *  in PIC32 devices.
*/

// *****************************************************************************
/* Register Operation:  Bit Set

  Summary:
    Sets the bit in the specified register.

  Description:
    This macro sets the specified bit in the specified register.
    The bit set is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeEnable ( USB_MODULE_ID index )
    {
        _SFR_BIT_SET(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                     _USB_VBUS_CHARGE_PULLUP_POS(index) );
    }
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-set instruction on
    processors that support bit-set instructions.  The specific instruction will
    be dependent on the architecture on which the macro is being used.

    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.
*/

#define _SFR_BIT_SET(reg,pos)        ( *((SFR_TYPE *)((reg)+(2))) = 1<<(pos) )


// *****************************************************************************
/* Register Operation:  Bit Clear

  Summary:
    Clears the bit in the specified register.

  Description:
    This macro clear the specified bit in the specified register.
    The bit cleared is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeDisable ( USB_MODULE_ID index )
    {
        _SFR_BIT_CLEAR(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                       _USB_VBUS_CHARGE_PULLUP_POS(index) );
    }
  </code>

  Remarks:
	This operation adds an offset of '1' to access the 'CLR' register
	corresponding to the register specified.
*/

#define _SFR_BIT_CLEAR(reg,pos)      ( *((SFR_TYPE *)((reg)+(1))) = 1<<(pos) )


// *****************************************************************************
/* Register Operation:  Bit Invert

  Summary:
    Inverts the bit in the specified register.

  Description:
    This macro invert the specified bit in the specified register.
    The bit inverted is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:

	This operation adds an offset of '3' to access the 'INV' register
	corresponding to the register specified.
*/

#define _SFR_BIT_INVERT(reg,pos)     ( *((SFR_TYPE *)((reg)+(3))) = 1<<(pos) )


// *****************************************************************************
/* Register Operation:  Field Set

  Summary:
    Sets bits in the field of a specified register.

  Description:
    This macro sets bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits set within the field are specified by the value.

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is set to "1", with the LSb of val justified to be at bit zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeEnable ( USB_MODULE_ID index )
    {
        _SFR_FIELD_SET(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                       _USB_VBUS_CHARGE_PULLUP_MASK(index),
                       _USB_VBUS_CHARGE_PULLUP_POS(index) ,
                       0x1                                );
    }
  </code>

  Remarks:

	This operation adds an offset of '2' to access the 'SET' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_FIELD_SET(reg,mask,pos,val)    (  *((SFR_TYPE *)((reg)+(2))) = ( (mask)&((val)<<(pos)) )  )


// *****************************************************************************
/* Register Operation:  Field Clear

  Summary:
    Clears bits in the field of a specified register

  Description:
    This macro clears bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits cleared within the field are specified by the value

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is cleared to "0", with the LSb of val justified to be at bit zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeDisable ( USB_MODULE_ID index )
    {
        _SFR_FIELD_CLEAR(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                         _USB_VBUS_CHARGE_PULLUP_MASK(index),
                         _USB_VBUS_CHARGE_PULLUP_POS(index) ,
                         0x1                                );
    }
  </code>

  Remarks:
	This operation adds an offset of '1' to access the 'CLR' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_FIELD_CLEAR(reg,mask,pos,val)  ( *((SFR_TYPE *)((reg)+(1))) = ( (mask)&((val)<<(pos)) ) )


// *****************************************************************************
/* Register Operation:  Field Invert

  Summary:
    Inverts bits in the field of a specified register

  Description:
    This macro inverts bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits inverted within the field are specified by the value

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is inverted (0->1,1->0), with the LSb of val justified
          to be at bit zero

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
	This operation adds an offset of '3' to access the 'INV' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_FIELD_INVERT(reg,mask,pos,val) (  *((SFR_TYPE *)((reg)+(3))) = ( (mask)&((val)<<(pos)) )  )


//******************************************************************************
/* Register Operation:  SFR Set

  Summary:
    Sets the bits of the specified register using the bit map provided.

  Description:
    Sets the bits of the specified register using the bit map provided.
    The bits set are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is set to "1".

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
	This operation adds an offset of '2' to access the 'SET' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_SET(reg,val)    ( *((SFR_TYPE *)((reg)+(2))) = (val) )


//******************************************************************************
/* Register Operation:  SFR Clear

  Summary:
    Clears the bits of the specified register using the bit map provided.

  Description:
    Clears the bits of the specified register using the bit map provided.
    The bits cleared are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is cleared to zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
	This operation adds an offset of '1' to access the 'CLR' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_CLEAR(reg,val)  ( *((SFR_TYPE *)((reg)+(1))) = (val) )


//******************************************************************************
/* Register Operation:  SFR Invert

  Summary:
    Inverts the bits of the specified register using the bit map provided.

  Description:
    Inverts the bits of the specified register using the bit map provided.
    The bits inverted are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is inverted (0->1,1->0).

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation adds an offset of '3' to access the 'INV' register
	corresponding to the register specified.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_INVERT(reg,val) ( *((SFR_TYPE *)((reg)+(3))) = (val) )


// *****************************************************************************
// *****************************************************************************
// Section: Register Access Macros for Bit Operations
// *****************************************************************************
// *****************************************************************************
/* These macros are used to access bits in registers in the peripheral libraries
*/

// *****************************************************************************
/* Register Operation:  Bit Read

  Summary:
    Reads the value of the bit in the specified register.

  Description:
    This macro reads (or tests) the specified bit in the specified register.
    The bit read is selected by the given bit position.

  Precondition:
    None.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    Bit value, either 0 or 1.

  Example:
  <code>
    PLIB_TEMPLATE bool PLIB_USB_OTG_BSessionEnd ( USB_MODULE_ID index )
    {
        return _SFR_BIT_READ(_USB_B_SESSION_END_VREG(index),
                             _USB_B_SESSION_END_POS(index) );
    }
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-get instruction on
    processors that support bit-get instructions.  The specific instruction will
    be dependent on the architecture on which the macro is being used.

    This operation is guaranteed to perform an atomic read of a register,
    provided it is not misused.  Registers do not normally span alignment
    boundaries, but if this macro is misused to span an alignment boundary,
    atomicity is no longer guaranteed.
*/

#define _SFR_BIT_READ(reg,pos)       (  ( ( *((SFR_TYPE *)(reg)) )&(1<<(pos)) ) ? 1 : 0  )


// *****************************************************************************
/* Register Operation:  Bit Write

  Summary:
    Writes the value of the bit into the specified register.

  Description:
    This macro writes the specified bit in the specified register.
    The bit written is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.
    val - new value of bit, either 0 or 1.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OnOff ( USB_MODULE_ID index, bool onOff )
    {
        _SFR_BIT_WRITE(_USB_POWERED_ON_VREG(index),
                       _USB_POWERED_ON_POS(index) ,
                       onOff                      );
    }
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-write instruction on
    processors that support bit-write instructions.  The specific instruction
    will be dependent on the architecture on which the macro is being used.

    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.
*/

#define _SFR_BIT_WRITE(reg,pos,val)  (  *((SFR_TYPE *)(reg)) = ( ( *((SFR_TYPE *)(reg)) ) & ~(1<<(pos)) ) | (0x1&(val))<<(pos)  )


// *****************************************************************************
/* Register Operation:  Bit Set

  Summary:
    Sets the bit in the specified register.

  Description:
    This macro sets the specified bit in the specified register.
    The bit set is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeEnable ( USB_MODULE_ID index )
    {
        _SFR_BIT_SET(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                     _USB_VBUS_CHARGE_PULLUP_POS(index) );
    }
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-set instruction on
    processors that support bit-set instructions.  The specific instruction will
    be dependent on the architecture on which the macro is being used.

    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.
*/

#ifndef _SFR_BIT_SET
#define _SFR_BIT_SET(reg,pos)        ( *((SFR_TYPE *)(reg)) |=  1<<(pos) )
#endif


// *****************************************************************************
/* Register Operation:  Bit Clear

  Summary:
    Clears the bit in the specified register.

  Description:
    This macro clear the specified bit in the specified register.
    The bit cleared is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeDisable ( USB_MODULE_ID index )
    {
        _SFR_BIT_CLEAR(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                       _USB_VBUS_CHARGE_PULLUP_POS(index) );
    }
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-clear instruction on
    processors that support bit-get instructions.  The specific instruction will
    be dependent on the architecture on which the macro is being used.

    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.
*/

#ifndef _SFR_BIT_CLEAR
#define _SFR_BIT_CLEAR(reg,pos)      ( *((SFR_TYPE *)(reg)) &= ~(1<<(pos)) )
#endif


// *****************************************************************************
/* Register Operation:  Bit Invert

  Summary:
    Inverts the bit in the specified register.

  Description:
    This macro invert the specified bit in the specified register.
    The bit inverted is selected by the given bit position.

  Parameters:
    reg - SFR register name.
    pos - bit position within register.

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    The compiler should optimize the macro to a single bit-invert instruction on
    processors that support bit-invert instructions.  The specific instruction will
    be dependent on the architecture on which the macro is being used.

    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.
*/

#ifndef _SFR_BIT_INVERT
#define _SFR_BIT_INVERT(reg,pos)     ( *((SFR_TYPE *)(reg)) ^=  1<<(pos) )
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Register Access Macros for Field Operations
// *****************************************************************************
// *****************************************************************************
/* These macros are used to access fields in registers in the peripheral
   libraries.
*/

// *****************************************************************************
/* Register Operation:  Field Read

  Summary:
    Reads the value of a field in the specified register.

  Description:
    This macro reads (or tests) the specified field in the specified register.
    The field read is selected by the given field position and field mask.

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.

  Returns:
    Value of the field within the SFR, with the LSb justified to be at bit zero.

  Example:
  <code>
    PLIB_TEMPLATE bool PLIB_USB_OTG_BSessionEnd ( USB_MODULE_ID index )
    {
        return _SFR_FIELD_READ(_USB_B_SESSION_END_VREG(index),
                               _USB_B_SESSION_END_MASK(index),
                               _USB_B_SESSION_END_POS(index) );
    }
  </code>

  Remarks:
    This operation is guaranteed to perform an atomic read of a register,
    provided it is not misused.  Registers do not normally span alignment
    boundaries, but if this macro is misused to span an alignment boundary,
    atomicity is no longer guaranteed.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_FIELD_READ(reg,mask,pos)       (  ( *((SFR_TYPE *)(reg))&(mask) ) >> (pos)  )


// *****************************************************************************
/* Register Operation:  Field Write

  Summary:
    Writes the value of the field into the specified register.

  Description:
    This macro writes the specified field in the specified register.
    The field written is selected by the given field position and field mask.

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - new value of field, with the LSb justified to be at bit zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OnOff ( USB_MODULE_ID index, bool onOff )
    {
        _SFR_FIELD_WRITE(_USB_POWERED_ON_VREG(index),
                         _USB_POWERED_ON_MASK(index),
                         _USB_POWERED_ON_POS(index) ,
                         onOff                      );
    }
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_FIELD_WRITE(reg,mask,pos,val)  \
    (  *((SFR_TYPE *)(reg)) = \
        ( (*((SFR_TYPE *)(reg))) & ~(mask) ) | ( (mask)&((val)<<(pos)) )  )


// *****************************************************************************
/* Register Operation:  Field Set

  Summary:
    Sets bits in the field of a specified register.

  Description:
    This macro sets bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits set within the field are specified by the value.

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is set to "1", with the LSb of val justified to be at bit zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeEnable ( USB_MODULE_ID index )
    {
        _SFR_FIELD_SET(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                       _USB_VBUS_CHARGE_PULLUP_MASK(index),
                       _USB_VBUS_CHARGE_PULLUP_POS(index) ,
                       0x1                                );
    }
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/
#ifndef _SFR_FIELD_SET
#define _SFR_FIELD_SET(reg,mask,pos,val)    (  *((SFR_TYPE *)(reg)) |=   ( (mask)&((val)<<(pos)) )  )
#endif


// *****************************************************************************
/* Register Operation:  Field Clear

  Summary:
    Clears bits in the field of a specified register

  Description:
    This macro clears bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits cleared within the field are specified by the value

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is cleared to "0", with the LSb of val justified to be at bit zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
    PLIB_TEMPLATE void PLIB_USB_OTG_VBusChargeDisable ( USB_MODULE_ID index )
    {
        _SFR_FIELD_CLEAR(_USB_VBUS_CHARGE_PULLUP_VREG(index),
                         _USB_VBUS_CHARGE_PULLUP_MASK(index),
                         _USB_VBUS_CHARGE_PULLUP_POS(index) ,
                         0x1                                );
    }
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#ifndef _SFR_FIELD_CLEAR
#define _SFR_FIELD_CLEAR(reg,mask,pos,val)  (  *((SFR_TYPE *)(reg)) &=  ~( (mask)&((val)<<(pos)) )  )
#endif


// *****************************************************************************
/* Register Operation:  Field Invert

  Summary:
    Inverts bits in the field of a specified register

  Description:
    This macro inverts bits in the specified field of the specified register.
    The field modified is selected by the given field position and field mask.
    The bits inverted within the field are specified by the value

  Parameters:
    reg - SFR register name.
    mask - field bit mask within the register.
    pos - bit position within register.
    val - Each "1" bit in val field indicates the corresponding bit in
          the field is inverted (0->1,1->0), with the LSb of val justified
          to be at bit zero

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#ifndef _SFR_FIELD_INVERT
#define _SFR_FIELD_INVERT(reg,mask,pos,val) (  *((SFR_TYPE *)(reg)) ^=   ( (mask)&((val)<<(pos)) )  )
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Register Access Macros for Field Operations
// *****************************************************************************
// *****************************************************************************
/* These macros are used to access registers in the peripheral  libraries.
*/

//******************************************************************************
/* Register Operation:  SFR Read

  Summary:
    Reads the value of the specified register

  Description:
    This macro reads the specified register.

  Parameters:
    reg - SFR register name.

  Returns:
    Value of SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is guaranteed to perform an atomic read of a register,
    provided it is not misused.  Registers do not normally span alignment
    boundaries, but if this macro is misused to span an alignment boundary,
    atomicity is no longer guaranteed.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_READ(reg)       ( *((SFR_TYPE *)(reg)) )


//******************************************************************************
/* Register Operation:  SFR Write

  Summary:
    Writes the specified register

  Description:
    This macro writes the specified register.

  Parameters:
    reg - SFR register name.
    val - new value of SFR register.

  Returns:
    New value of SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#define _SFR_WRITE(reg,val)  ( *((SFR_TYPE *)(reg))  =  (val) )


//******************************************************************************
/* Register Operation:  SFR Set

  Summary:
    Sets the bits of the specified register using the bit map provided.

  Description:
    Sets the bits of the specified register using the bit map provided.
    The bits set are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is set to "1".

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#ifndef _SFR_SET
#define _SFR_SET(reg,val)    ( *((SFR_TYPE *)(reg)) |=  (val) )
#endif


//******************************************************************************
/* Register Operation:  SFR Clear

  Summary:
    Clears the bits of the specified register using the bit map provided.

  Description:
    Clears the bits of the specified register using the bit map provided.
    The bits cleared are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is cleared to zero.

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#ifndef _SFR_CLEAR
#define _SFR_CLEAR(reg,val)  ( *((SFR_TYPE *)(reg)) &= ~(val) )
#endif


//******************************************************************************
/* Register Operation:  SFR Invert

  Summary:
    Inverts the bits of the specified register using the bit map provided.

  Description:
    Inverts the bits of the specified register using the bit map provided.
    The bits inverted are specified in the value provided.

  Parameters:
    reg - SFR register name.
    val - Each "1" bit in val indicates the corresponding bit in
          the register is inverted (0->1,1->0).

  Returns:
    New value of the SFR register.

  Example:
  <code>
  </code>

  Remarks:
    This operation is not guaranteed to access the register atomically.
    It may perform a read-modify-write operation.

    Positions are measured from the least significant bit (LSb) of the register.
    Masks are position aligned.
    Values are zero aligned.
*/

#ifndef _SFR_INVERT
#define _SFR_INVERT(reg,val) ( *((SFR_TYPE *)(reg)) ^=  (val) )
#endif


// *****************************************************************************
// *****************************************************************************
// Section: Helper Macros
// *****************************************************************************
// *****************************************************************************
/* These macros DO NOT access the registers in the processor.  These are helper
   macros to generate masks, access bytes or generate common error messages.
*/

// *****************************************************************************
/* Helper Macro:  Access Byte

  Summary:
    Accesses the specified byte in a 16- or 32-bit word

  Description:
    This macro accesses the specified byte in a 16- and 32-bit word.
    
  Remarks:
    Byte 0 is the low order byte in a 16- or 32-bit word
    Byte 1 is the hight-order byte in a 16-bit word or the second byte in a 
           32-bit word
    Byte 2 is the third byte in a 32-bit word
    Byte 3 is the high-order byte in a 32-bit word
*/

#define _PLIB_ACCESS_BYTE(value,index)    (((value) >> (index)*8) & 0xFF)


// *****************************************************************************
/* Helper Macro:  Access Double-Byte

  Summary:
    Accesses the specified double-byte (16-bit value) in a 32-bit word

  Description:
    This macro accesses the specified double-byte in a 32-bit word.
    
  Remarks:
    Double-Byte 0 is the low-order 16-bits in a 32-bit word
    Double-Byte 1 is the high-order 16-bits in a 32-bit word
*/

#define _PLIB_ACCESS_DOUBLE_BYTE(value, index)   (((value) >> (index)*16) & 0xFFFF)


// *****************************************************************************
/* Helper Macro:  Unsupported Attribute Abstraction

  Summary:
    Abstracts the use of the unsupported attribute defined by the compiler

  Description:
    This macro abstracts the definition of the unsupported attribute as defined
    by the compiler. This macro is to be used as an attribute for the interface
    definitions which are not supported by the part selected by the user.

  Example:
    void _PLIB_UNSUPPORTED PLIB_USART_Enable(USART_MODULE_ID index);

    Generates a compiler error, if the interface is not defined for the
    part selected.

 Remarks:
    This macro is defined for each compiler individually currently, so as to
    account for the compiler differences in implementing the attribute.

    This macro provides a PLIB-related message when unsupported PLIB routines
    and data types are instantiated.  Thus, it is part of the peripheral
    library implementation and prefixed with a single underscore.
*/
    
#ifndef _PLIB_UNSUPPORTED

    #define _PLIB_UNSUPPORTED   __attribute__((unsupported("The microcontroller selected does not implement this feature.")))

#endif


/*******************************************************************************
  Function:
    void PLIB_ASSERT ( bool test, char *message )

  Summary:
    Implements default PLIB assert routine, asserts that "test" is true

  Description:
    This macro implements the default PLIB assert routine that asserts that a
    test is true.

  Precondition:
    None.

  Parameters:
    test     - This is an expression that resolves to a boolean value
               (zero=false, non-zero=true)

    message  - This is a NULL-terminated character string that can be displayed
               on a debug output terminal if "test" is false (if supported)

  Returns:
    None     - Normally hangs in a loop

  Example:
    <code>
    void MyFunc ( int *pointer )
    {
        PLIB_ASSERT(NULL != pointer, "NULL Pointer passed to MyFunc");

        //...
    }
    </code>

  Remarks:
    Can be overridden as desired by defining your own PLIB_ASSERT macro before
    including plib.h.

    By default, this is equated to SYS_ASSERT" if it is defined.  If "SYS_ASSERT" 
    is not defined, it defaults to the compiler's "assert" function.
*/

#ifndef PLIB_ASSERT

    #if defined(SYS_ASSERT)

        #define PLIB_ASSERT(test,message)   SYS_ASSERT(test,message)

    #else

        #define PLIB_ASSERT(test,message)

    #endif

#endif



#ifdef	__cplusplus
}
#endif

#endif	/* COMMON_H */

