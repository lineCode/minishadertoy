#pragma once

#ifdef _DEBUG
void CheckGLErrors(const char *func, int line);
#define GLCHK glFinish(); CheckGLErrors(__FUNCTION__, __LINE__);
#else
#define GLCHK
#endif

typedef struct FBO
{
    const char *id;
    GLuint framebuffer;
    GLuint framebufferTex;
    int floatTex;
} FBO;

typedef struct SAMPLER
{
    int filter, wrap, vflip, srgb, internal;
} SAMPLER;

typedef struct SHADER_INPUT
{
    const char *id;
    GLuint tex;
    int is_cubemap, w, h;
    SAMPLER sampler;
} SHADER_INPUT;

typedef struct SHADER
{
    GLuint prog;
    GLuint shader;
    SHADER_INPUT inputs[4];
    FBO output;
    int type;

    GLuint iResolution;
    GLuint iTime;
    GLuint iTimeDelta;
    GLuint iFrame;
    GLuint iMouse;
    GLuint iDate;
    GLuint iSampleRate;
    GLuint iChannelTime[4];
    GLuint iChannelResolution[4];
    GLuint iChannel[4];
} SHADER;

typedef struct PLATFORM_PARAMS
{
    int winWidth, winHeight, frame;
    float mx, my, cx, cy, cur_time, time_last;
    struct tm *tm;
} PLATFORM_PARAMS;
