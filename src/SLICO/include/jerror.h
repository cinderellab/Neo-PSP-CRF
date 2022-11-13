/*
 * jerror.h
 *
 * Copyright (C) 1994-1997, Thomas G. Lane.
 * Modified 1997-2012 by Guido Vollbeding.
 * This file is part of the Independent JPEG Group's software.
 * For conditions of distribution and use, see the accompanying README file.
 *
 * This file defines the error and message codes for the JPEG library.
 * Edit this file to add new codes, or to translate the message strings to
 * some other language.
 * A set of error-reporting macros are defined too.  Some applications using
 * the JPEG library may wish to include this file to get the error codes
 * and/or the macros.
 */

/*
 * To define the enum list of message codes, include this file without
 * defining macro JMESSAGE.  To create a message string table, include it
 * again with a suitable JMESSAGE definition (see jerror.c for an example).
 */
#ifndef JMESSAGE
#ifndef JERROR_H
/* First time through, define the enum list */
#define JMAKE_ENUM_LIST
#else
/* Repeated inclusions of this file are no-ops unless JMESSAGE is defined */
#define JMESSAGE(code,string)
#endif /* JERROR_H */
#endif /* JMESSAGE */

#ifdef JMAKE_ENUM_LIST

typedef enum {

#define JMESSAGE(code,string)	code ,

#endif /* JMAKE_ENUM_LIST */

JMESSAGE(JMSG_NOMESSAGE, "Bogus message code %d") /* Must be first entry! */

/* For maintenance convenience, list is alphabetical by message code name */
JMESSAGE(JERR_BAD_ALIGN_TYPE, "ALIGN_TYPE is wrong, please fix")
JMESSAGE(JERR_BAD_ALLOC_CHUNK, "MAX_ALLOC_CHUNK is wrong, please fix")
JMESSAGE(JERR_BAD_BUFFER_MODE, "Bogus buffer control mode")
JMESSAGE(JERR_BAD_COMPONENT_ID, "Invalid component ID %d in SOS")
JMESSAGE(JERR_BAD_CROP_SPEC, "Invalid crop request")
JMESSAGE(JERR_BAD_DCT_COEF, "DCT coefficient out of range")
JMESSAGE(JERR_BAD_DCTSIZE, "DCT scaled block size %dx%d not supported")
JMESSAGE(JERR_BAD_DROP_SAMPLING,
	 "Component index %d: mismatching sampling ratio %d:%d, %d:%d, %c")
JMESSAGE(JERR_BAD_HUFF_TABLE, "Bogus Huffman table definition")
JMESSAGE(JERR_BAD_IN_COLORSPACE, "Bogus input colorspace")
JMESSAGE(JERR_BAD_J_COLORSPACE, "Bogus JPEG colorspace")
JMESSAGE(JERR_BAD_LENGTH, "Bogus marker length")
JMESSAGE(JERR_BAD_LIB_VERSION,
	 "Wrong JPEG library version: library is %d, caller expects %d")
JMESSAGE(JERR_BAD_MCU_SIZE, "Sampling factors too large for interleaved scan")
JMESSAGE(JERR_BAD_POOL_ID, "Invalid memory pool code %d")
JMESSAGE(JERR_BAD_PRECISION, "Unsupported JPEG data precision %d")
JMESSAGE(JERR_BAD_PROGRESSION,
	 "Invalid progressive parameters Ss=%d Se=%d Ah=%d Al=%d")
JMESSAGE(JERR_BAD_PROG_SCRIPT,
	 "Invalid progressive parameters at scan script entry %d")
JMESSAGE(JERR_BAD_SAMPLING, "Bogus sampling factors")
JMESSAGE(JERR_BAD_SCAN_SCRIPT, "Invalid scan script at entry %d")
JMESSAGE(JERR_BAD_STATE, "Improper call to JPEG library in state %d")
JMESSAGE(JERR_BAD_STRUCT_SIZE,
	 "JPEG parameter struct mismatch: library thinks size is %u, caller expects %u")
JMESSAGE(JERR_BAD_VIRTUAL_ACCESS, "Bogus virtual array access")
JMESSAGE(JERR_BUFFER_SIZE, "Buffer passed to JPEG library is too small")
JMESSAGE(JERR_CANT_SUSPEND, "Suspension not allowed here")
JMESSAGE(JERR_CCIR601_NOTIMPL, "CCIR601 sampling not implemented yet")
JMESSAGE(JERR_COMPONENT_COUNT, "Too many color components: %d, max %d")
JMESSAGE(JERR_CONVERSION_NOTIMPL, "Unsupported color conversion request")
JMESSAGE(JERR_DAC_INDEX, "Bogus DAC index %d")
JMESSAGE(JERR_DAC_VALUE, "Bogus DAC value 0x%x")
JMESSAGE(JERR_DHT_INDEX, "Bogus DHT index %d")
JMESSAGE(JERR_DQT_INDEX, "Bogus DQT index %d")
JMESSAGE(JERR_EMPTY_IMAGE, "Empty JPEG image (DNL not supported)")
JMESSAGE(JERR_EMS_READ, "Read from EMS failed")
JMESSAGE(JERR_EMS_WRITE, "Write to EMS failed")
JMESSAGE(JERR_EOI_EXPECTED, "Didn't expect more than one scan")
JMESSAGE(JERR_FILE_READ, "Input file read error")
JMESSAGE(JERR_FILE_WRITE, "Output file write error --- out of disk space?")
JMESSAGE(JERR_FRACT_SAMPLE_NOTIMPL, "Fractional sampling not implemented yet")
JMESSAGE(JERR_HUFF_CLEN_OVERFLOW, "Huffman code size table overflow")
JMESSAGE(JERR_HUFF_MISSING_CODE, "Missing Huffman code table entry")
JMESSAGE(JERR_IMAGE_TOO_BIG, "Maximum supported image dimension is %u pixels")
JMESSAGE(JERR_INPUT_EMPTY, "Empty input file")
JMESSAGE(JERR_INPUT_EOF, "Premature end of input file")
JMESSAGE(JERR_MISMATCHED_QUANT_TABLE,
	 "Cannot transcode due to multiple use of quantization table %d")
JMESSAGE(JERR_MISSING_DATA, "Scan script does not transmit all data")
JMESSAGE(JERR_MODE_CHANGE, "Invalid color quantization mode change")
JMESSAGE(JERR_NOTIMPL, "Not implemented yet")
JMESSAGE(JERR_NOT_COMPILED, "Requested feature was omitted at compile time")
JMESSAGE(JERR_NO_ARITH_TABLE, "Arithmetic table 0x%02x was not defined")
JMESSAGE(JERR_NO_BACKING_STORE, "Backing store not supported")
JMESSAGE(JERR_NO_HUFF_TABLE, "Huffman table 0x%02x was not defined")
JMESSAGE(JERR_NO_IMAGE, "JPEG datastream contains no image")
JMESSAGE(JERR_NO_QUANT_TABLE, "Quantization table 0x%02x was not defined")
JMESSAGE(JERR_NO_SOI, "Not a JPEG file: starts with 0x%02x 0x%02x")
JMESSAGE(JERR_OUT_OF_MEMORY, "Insufficient memory (case %d)")
JMESSAGE(JERR_QUANT_COMPONENTS,
	 "Cannot quantize more than %d color components")
JMESSAGE(JERR_QUANT_FEW_COLORS, "Cannot quantize to fewer than %d colors")
JMESSAGE(JERR_QUANT_MANY_COLORS, "Cannot quantize to more than %d colors")
JMESSAGE(JERR_SOF_BEFORE, "Invalid JPEG file structure: %s before SOF")
JMESSAGE(JERR_SOF_DUPLICATE, "Invalid JPEG file structure: two SOF markers")
JMESSAGE(JERR_SOF_NO_SOS, "Invalid JPEG file structure: missing SOS marker")
JMESSAGE(JERR_SOF_UNSUPPORTED, "Unsupported JPEG process: SOF type 0x%02x")
JMESSAGE(JERR_SOI_DUPLICATE, "Invalid JPEG file structure: two SOI markers")
JMESSAGE(JERR_TFILE_CREATE, "Failed to create temporary file