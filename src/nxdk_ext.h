#ifndef NXDK_EXT_H__
#define NXDK_EXT_H__

// TODO: upstream missing nv2a defines
// See
// https://github.com/xqemu/xqemu/blob/f9b9a9bad88b3b2df53a1b01db6a37783aa2eb27/hw/xbox/nv2a/nv2a_shaders.c#L296-L312
#define NV2A_VERTEX_ATTR_POSITION 0
#define NV2A_VERTEX_ATTR_WEIGHT 1
#define NV2A_VERTEX_ATTR_NORMAL 2
#define NV2A_VERTEX_ATTR_DIFFUSE 3
#define NV2A_VERTEX_ATTR_SPECULAR 4
#define NV2A_VERTEX_ATTR_FOG_COORD 5
#define NV2A_VERTEX_ATTR_POINT_SIZE 6
#define NV2A_VERTEX_ATTR_BACK_DIFFUSE 7
#define NV2A_VERTEX_ATTR_BACK_SPECULAR 8
#define NV2A_VERTEX_ATTR_TEXTURE0 9
#define NV2A_VERTEX_ATTR_TEXTURE1 10
#define NV2A_VERTEX_ATTR_TEXTURE2 11
#define NV2A_VERTEX_ATTR_TEXTURE3 12
// These do not have a default semantic but are usable from custom vertex shaders.
#define NV2A_VERTEX_ATTR_13 13
#define NV2A_VERTEX_ATTR_14 14
#define NV2A_VERTEX_ATTR_15 15

#define NV097_SET_ZMIN_MAX_CONTROL_CULL_NEAR_FAR_EN_FALSE 0
#define NV097_SET_ZMIN_MAX_CONTROL_CULL_NEAR_FAR_EN_TRUE NV097_SET_ZMIN_MAX_CONTROL_CULL_NEAR_FAR
#define NV097_SET_ZMIN_MAX_CONTROL_ZCLAMP_EN_CULL 0
#define NV097_SET_ZMIN_MAX_CONTROL_ZCLAMP_EN_CLAMP NV097_SET_ZMIN_MAX_CONTROL_ZCLAMP_CLAMP
#define NV097_SET_ZMIN_MAX_CONTROL_CULL_IGNORE_W_FALSE 0
#define NV097_SET_ZMIN_MAX_CONTROL_CULL_IGNORE_W_TRUE NV097_SET_ZMIN_MAX_CONTROL_CULL_IGNORE_W

// Naming from xemu's nv2a_regs.h, to be used with nxdk's NV_IMAGE_BLIT definitions.
#define NV09F_SET_OPERATION_BLEND_AND 0x02
#define NV09F_SET_OPERATION_SRCCOPY 0x03
#define NV09F_SET_OPERATION_SRCCOPY_PREMULT 0x04
#define NV09F_SET_OPERATION_BLEND_AND_PREMULT 0x05

#define NV_IMAGE_BLIT_SET_BETA 0x0194
#define NV_IMAGE_BLIT_SET_BETA4 0x0198

#define NV012_BETA 0x00000012  // Alpha factor
#define NV012_SET_BETA 0x0300

#define NV072_BETA_4 0x00000072  // RGBA factor
#define NV072_SET_BETA 0x0300

#define NV04_SURFACE_2D_FORMAT_Y8 0x00000001
#define NV04_SURFACE_2D_FORMAT_X1R5G5B5_Z1R5G5B5 0x00000002
#define NV04_SURFACE_2D_FORMAT_X1R5G5B5_X1R5G5B5 0x00000003
#define NV04_SURFACE_2D_FORMAT_R5G6B5 0x00000004
#define NV04_SURFACE_2D_FORMAT_Y16 0x00000005
#define NV04_SURFACE_2D_FORMAT_X8R8G8B8_Z8R8G8B8 0x00000006
#define NV04_SURFACE_2D_FORMAT_X8R8G8B8_X8R8G8B8 0x00000007
#define NV04_SURFACE_2D_FORMAT_X1A7R8G8B8_Z1A7R8G8B8 0x00000008
#define NV04_SURFACE_2D_FORMAT_X1A7R8G8B8_X1A7R8G8B8 0x00000009
#define NV04_SURFACE_2D_FORMAT_A8R8G8B8 0x0000000a
#define NV04_SURFACE_2D_FORMAT_Y32 0x0000000b

// From https://github.com/xemu-project/xemu/pull/1937#issuecomment-2692650398
#define NV097_SET_CONTROL0_TEXTURE_PERSPECTIVE_ENABLE (1 << 20)

// Used to set light parameters for lights beyond 0.
// Supported params:
//    NV097_SET_LIGHT_AMBIENT_COLOR
//    NV097_SET_LIGHT_DIFFUSE_COLOR
//    NV097_SET_LIGHT_SPECULAR_COLOR
//    NV097_SET_LIGHT_LOCAL_RANGE
//    NV097_SET_LIGHT_INFINITE_HALF_VECTOR
//    NV097_SET_LIGHT_INFINITE_DIRECTION
//    NV097_SET_LIGHT_SPOT_FALLOFF
//    NV097_SET_LIGHT_SPOT_DIRECTION
//    NV097_SET_LIGHT_LOCAL_POSITION
//    NV097_SET_LIGHT_LOCAL_ATTENUATION
#define SET_LIGHT(i, param) ((param) + (i) * 128)

// Used to set light parameters for back lights beyond 0.
// Supported params:
//    NV097_SET_BACK_LIGHT_AMBIENT_COLOR
//    NV097_SET_BACK_LIGHT_DIFFUSE_COLOR
//    NV097_SET_BACK_LIGHT_SPECULAR_COLOR
#define SET_BACK_LIGHT(i, param) ((param) + (i) * 64)

// Used to enable/disable a specific light.
// Mode must be one of the `NV097_SET_LIGHT_ENABLE_MASK_LIGHT0_*` values.
#define LIGHT_MODE(i, mode) ((mode) << (2 * (i)))

#define NV097_SET_SPECULAR_PARAMS 0x9E0

#define NV042_SET_PITCH 0x304
#define NV042_SET_COLOR_FORMAT NV04_CONTEXT_SURFACES_2D_FORMAT
#define NV042_SET_COLOR_FORMAT_LE_A8R8G8B8 0x0A

#define NV05C_SET_COLOR_FORMAT_LE_X16R5G6B5 0x00000001
#define NV05C_SET_COLOR_FORMAT_LE_X17R5G5B5 0x00000002
#define NV05C_SET_COLOR_FORMAT_LE_X8R8G8B8 0x00000003

// NV_PGRAPH_TEXFILTER0_CONVOLUTION_KERNEL from xemu.
#define NV097_SET_TEXTURE_FILTER_CONVOLUTION_KERNEL 0x0000E000

#define NV062_SET_COLOR_FORMAT NV10_CONTEXT_SURFACES_2D_FORMAT
#define NV062_SET_PITCH NV10_CONTEXT_SURFACES_2D_PITCH
#define NV062_SET_OFFSET_SOURCE NV10_CONTEXT_SURFACES_2D_OFFSET_SRC
#define NV062_SET_OFFSET_DESTIN NV10_CONTEXT_SURFACES_2D_OFFSET_DST

#define NV09F_CONTROL_POINT_IN NV_IMAGE_BLIT_POINT_IN
#define NV09F_CONTROL_POINT_OUT NV_IMAGE_BLIT_POINT_OUT
#define NV09F_SIZE NV_IMAGE_BLIT_SIZE

#define NV097_SET_SMOOTHING_CONTROL 0x00001D7C

#define NV097_SET_STENCIL_FUNC_V_NEVER 0x200
#define NV097_SET_STENCIL_FUNC_V_LESS 0x201
#define NV097_SET_STENCIL_FUNC_V_EQUAL 0x202
#define NV097_SET_STENCIL_FUNC_V_LEQUAL 0x203
#define NV097_SET_STENCIL_FUNC_V_GREATER 0x204
#define NV097_SET_STENCIL_FUNC_V_NOTEQUAL 0x205
#define NV097_SET_STENCIL_FUNC_V_GEQUAL 0x206
#define NV097_SET_STENCIL_FUNC_V_ALWAYS 0x207

// NV_PVIDEO_INTR is already defined in outer.h
#define NV_PVIDEO_INTR_BUFFER_0 (1 << 0)
#define NV_PVIDEO_INTR_BUFFER_1 (1 << 4)
#define NV_PVIDEO_INTR_EN 0x00008140
#define NV_PVIDEO_INTR_EN_BUFFER_0 (1 << 0)
#define NV_PVIDEO_INTR_EN_BUFFER_1 (1 << 4)
#define NV_PVIDEO_BUFFER 0x00008700
#define NV_PVIDEO_BUFFER_0_USE (1 << 0)
#define NV_PVIDEO_BUFFER_1_USE (1 << 4)
#define NV_PVIDEO_STOP 0x00008704
#define NV_PVIDEO_BASE 0x00008900
#define NV_PVIDEO_LIMIT 0x00008908
#define NV_PVIDEO_LUMINANCE 0x00008910
#define NV_PVIDEO_CHROMINANCE 0x00008918
#define NV_PVIDEO_OFFSET 0x00008920
#define NV_PVIDEO_SIZE_IN 0x00008928
#define NV_PVIDEO_SIZE_IN_WIDTH 0x000007FF
#define NV_PVIDEO_SIZE_IN_HEIGHT 0x07FF0000
#define NV_PVIDEO_POINT_IN 0x00008930
#define NV_PVIDEO_POINT_IN_S 0x00007FFF
#define NV_PVIDEO_POINT_IN_T 0xFFFE0000
#define NV_PVIDEO_DS_DX 0x00008938
#define NV_PVIDEO_DT_DY 0x00008940
#define NV_PVIDEO_POINT_OUT 0x00008948
#define NV_PVIDEO_POINT_OUT_X 0x00000FFF
#define NV_PVIDEO_POINT_OUT_Y 0x0FFF0000
#define NV_PVIDEO_SIZE_OUT 0x00008950
#define NV_PVIDEO_SIZE_OUT_WIDTH 0x00000FFF
#define NV_PVIDEO_SIZE_OUT_HEIGHT 0x0FFF0000
#define NV_PVIDEO_FORMAT 0x00008958
#define NV_PVIDEO_FORMAT_PITCH 0x00001FFF
#define NV_PVIDEO_FORMAT_COLOR 0x00030000
#define NV_PVIDEO_FORMAT_COLOR_LE_CR8YB8CB8YA8 1
#define NV_PVIDEO_FORMAT_DISPLAY (1 << 20)
#define NV_PVIDEO_FORMAT_DISPLAY_COLOR_KEY 1
#define NV_PVIDEO_COLOR_KEY 0x00008B00
#define NV_PVIDEO_COLOR_KEY_RED 0x00FF0000
#define NV_PVIDEO_COLOR_KEY_GREEN 0x0000FF00
#define NV_PVIDEO_COLOR_KEY_BLUE 0x000000FF
#define NV_PVIDEO_COLOR_KEY_ALPHA 0xFF000000

#define NV097_SET_SWATH_WIDTH 0x000009f8
#define NV097_SET_SWATH_WIDTH_V_00 0x00
#define NV097_SET_SWATH_WIDTH_V_01 0x01
#define NV097_SET_SWATH_WIDTH_V_02 0x02
#define NV097_SET_SWATH_WIDTH_V_03 0x03
#define NV097_SET_SWATH_WIDTH_V_04 0x04
#define NV097_SET_SWATH_WIDTH_V_OFF 0x0F

#endif  // NXDK_EXT_H__
