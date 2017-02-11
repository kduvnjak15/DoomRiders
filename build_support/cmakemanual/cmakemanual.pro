TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += \
    ../../Include

SOURCES += \
    ../../Src/main.cpp \
    ../../Src/kinematics.cpp \
    ../../Src/DoomRiders.cpp \
    ../../Src/GameShader.cpp \
    ../../Src/math_3d.cpp \
    ../../Src/ogldev_util.cpp \
    ../../Src/pipeline.cpp \
    ../CMakeFiles/3.0.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    ../CMakeFiles/3.5.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    ../CMakeFiles/feature_tests.cxx \
    ../../Include/FreetypeGL/font_shader.cpp \
    ../../Include/FreetypeGL/freetypeGL.cpp \
    ../../Src/DR_Pipeline.cpp \
    ../CMakeFiles/3.0.2/CompilerIdC/CMakeCCompilerId.c \
    ../CMakeFiles/3.5.2/CompilerIdC/CMakeCCompilerId.c \
    ../CMakeFiles/feature_tests.c \
    ../../Include/FreetypeGL/font-manager.c \
    ../../Include/FreetypeGL/texture-atlas.c \
    ../../Include/FreetypeGL/texture-font.c \
    ../../Include/FreetypeGL/texture-glyph.c \
    ../../Include/FreetypeGL/vector.c \
    ../../Include/FreetypeGL/vertex-buffer.c \
    ../../Src/DR_GameShader.cpp \
    ../../Src/DR_Spectator.cpp \
    ../../Src/DR_ModelLoader.cpp \
    ../../Include/SOIL/src/test_SOIL.cpp \
    ../../Src/DR_Skybox.cpp \
    ../../Src/DR_Texture.cpp \
    ../../Include/SOIL/src/original/stb_image-1.09.c \
    ../../Include/SOIL/src/original/stb_image-1.16.c \
    ../../Include/SOIL/src/image_DXT.c \
    ../../Include/SOIL/src/image_helper.c \
    ../../Include/SOIL/src/SOIL.c \
    ../../Include/SOIL/src/stb_image_aug.c

HEADERS += \
    ../../Include/GL/freeglut.h \
    ../../Include/GL/freeglut_ext.h \
    ../../Include/GL/freeglut_std.h \
    ../../Include/GL/glew.h \
    ../../Include/GL/glxew.h \
    ../../Include/GL/wglew.h \
    ../../Include/glfx.h \
    ../../Include/ogldev.h \
    ../../Include/ogldev_app.h \
    ../../Include/ogldev_atb.h \
    ../../Include/ogldev_backend.h \
    ../../Include/ogldev_basic_lighting.h \
    ../../Include/ogldev_basic_mesh.h \
    ../../Include/ogldev_callbacks.h \
    ../../Include/ogldev_camera.h \
    ../../Include/ogldev_cubemap_texture.h \
    ../../Include/ogldev_engine_common.h \
    ../../Include/ogldev_glfw_backend.h \
    ../../Include/ogldev_glut_backend.h \
    ../../Include/ogldev_io_buffer.h \
    ../../Include/ogldev_keys.h \
    ../../Include/ogldev_lights_common.h \
    ../../Include/ogldev_math_3d.h \
    ../../Include/ogldev_pipeline.h \
    ../../Include/ogldev_random_texture.h \
    ../../Include/ogldev_shadow_map_fbo.h \
    ../../Include/ogldev_skinned_mesh.h \
    ../../Include/ogldev_texture.h \
    ../../Include/ogldev_types.h \
    ../../Include/ogldev_util.h \
    ../../Include/ogldev_vulkan.h \
    ../../Include/ogldev_vulkan_core.h \
    ../../Include/ogldev_win32_control.h \
    ../../Include/ogldev_xcb_control.h \
    ../../Include/technique.h \
    ../../Include/kinematics.h \
    ../../Src/GameShader.h \
    ../../Include/assimp/Compiler/poppack1.h \
    ../../Include/assimp/Compiler/pushpack1.h \
    ../../Include/assimp/ai_assert.h \
    ../../Include/assimp/anim.h \
    ../../Include/assimp/camera.h \
    ../../Include/assimp/cexport.h \
    ../../Include/assimp/cfileio.h \
    ../../Include/assimp/cimport.h \
    ../../Include/assimp/color4.h \
    ../../Include/assimp/config.h \
    ../../Include/assimp/DefaultLogger.hpp \
    ../../Include/assimp/defs.h \
    ../../Include/assimp/Exporter.hpp \
    ../../Include/assimp/Importer.hpp \
    ../../Include/assimp/importerdesc.h \
    ../../Include/assimp/IOStream.hpp \
    ../../Include/assimp/IOSystem.hpp \
    ../../Include/assimp/light.h \
    ../../Include/assimp/Logger.hpp \
    ../../Include/assimp/LogStream.hpp \
    ../../Include/assimp/material.h \
    ../../Include/assimp/matrix3x3.h \
    ../../Include/assimp/matrix4x4.h \
    ../../Include/assimp/mesh.h \
    ../../Include/assimp/NullLogger.hpp \
    ../../Include/assimp/postprocess.h \
    ../../Include/assimp/ProgressHandler.hpp \
    ../../Include/assimp/quaternion.h \
    ../../Include/assimp/scene.h \
    ../../Include/assimp/texture.h \
    ../../Include/assimp/types.h \
    ../../Include/assimp/vector2.h \
    ../../Include/assimp/vector3.h \
    ../../Include/assimp/version.h \
    ../../Include/ATB/AntTweakBar.h \
    ../../Include/freetype2/config/ftconfig.h \
    ../../Include/freetype2/config/ftheader.h \
    ../../Include/freetype2/config/ftmodule.h \
    ../../Include/freetype2/config/ftoption.h \
    ../../Include/freetype2/config/ftstdlib.h \
    ../../Include/freetype2/freetype.h \
    ../../Include/freetype2/ft2build.h \
    ../../Include/freetype2/ftadvanc.h \
    ../../Include/freetype2/ftautoh.h \
    ../../Include/freetype2/ftbbox.h \
    ../../Include/freetype2/ftbdf.h \
    ../../Include/freetype2/ftbitmap.h \
    ../../Include/freetype2/ftbzip2.h \
    ../../Include/freetype2/ftcache.h \
    ../../Include/freetype2/ftcffdrv.h \
    ../../Include/freetype2/ftchapters.h \
    ../../Include/freetype2/ftcid.h \
    ../../Include/freetype2/fterrdef.h \
    ../../Include/freetype2/fterrors.h \
    ../../Include/freetype2/ftgasp.h \
    ../../Include/freetype2/ftglyph.h \
    ../../Include/freetype2/ftgxval.h \
    ../../Include/freetype2/ftgzip.h \
    ../../Include/freetype2/ftimage.h \
    ../../Include/freetype2/ftincrem.h \
    ../../Include/freetype2/ftlcdfil.h \
    ../../Include/freetype2/ftlist.h \
    ../../Include/freetype2/ftlzw.h \
    ../../Include/freetype2/ftmac.h \
    ../../Include/freetype2/ftmm.h \
    ../../Include/freetype2/ftmodapi.h \
    ../../Include/freetype2/ftmoderr.h \
    ../../Include/freetype2/ftotval.h \
    ../../Include/freetype2/ftoutln.h \
    ../../Include/freetype2/ftpfr.h \
    ../../Include/freetype2/ftrender.h \
    ../../Include/freetype2/ftsizes.h \
    ../../Include/freetype2/ftsnames.h \
    ../../Include/freetype2/ftstroke.h \
    ../../Include/freetype2/ftsynth.h \
    ../../Include/freetype2/ftsystem.h \
    ../../Include/freetype2/fttrigon.h \
    ../../Include/freetype2/ftttdrv.h \
    ../../Include/freetype2/fttypes.h \
    ../../Include/freetype2/ftwinfnt.h \
    ../../Include/freetype2/ftxf86.h \
    ../../Include/freetype2/t1tables.h \
    ../../Include/freetype2/ttnameid.h \
    ../../Include/freetype2/tttables.h \
    ../../Include/freetype2/tttags.h \
    ../../Include/freetype2/ttunpat.h \
    ../../Include/FreetypeGL/font-manager.h \
    ../../Include/FreetypeGL/font_shader.h \
    ../../Include/FreetypeGL/freetypeGL.h \
    ../../Include/FreetypeGL/markup.h \
    ../../Include/FreetypeGL/texture-atlas.h \
    ../../Include/FreetypeGL/texture-font.h \
    ../../Include/FreetypeGL/texture-glyph.h \
    ../../Include/FreetypeGL/vector.h \
    ../../Include/FreetypeGL/vertex-buffer.h \
    ../../Include/GLFW/glfw3.h \
    ../../Include/GLFW/glfw3native.h \
    ../../Include/ImageMagick-6/magick/accelerate.h \
    ../../Include/ImageMagick-6/magick/animate-private.h \
    ../../Include/ImageMagick-6/magick/animate.h \
    ../../Include/ImageMagick-6/magick/annotate.h \
    ../../Include/ImageMagick-6/magick/api.h \
    ../../Include/ImageMagick-6/magick/artifact.h \
    ../../Include/ImageMagick-6/magick/attribute.h \
    ../../Include/ImageMagick-6/magick/blob-private.h \
    ../../Include/ImageMagick-6/magick/blob.h \
    ../../Include/ImageMagick-6/magick/cache-private.h \
    ../../Include/ImageMagick-6/magick/cache-view.h \
    ../../Include/ImageMagick-6/magick/cache.h \
    ../../Include/ImageMagick-6/magick/channel.h \
    ../../Include/ImageMagick-6/magick/cipher.h \
    ../../Include/ImageMagick-6/magick/client.h \
    ../../Include/ImageMagick-6/magick/coder.h \
    ../../Include/ImageMagick-6/magick/color-private.h \
    ../../Include/ImageMagick-6/magick/color.h \
    ../../Include/ImageMagick-6/magick/colormap-private.h \
    ../../Include/ImageMagick-6/magick/colormap.h \
    ../../Include/ImageMagick-6/magick/colorspace-private.h \
    ../../Include/ImageMagick-6/magick/colorspace.h \
    ../../Include/ImageMagick-6/magick/compare.h \
    ../../Include/ImageMagick-6/magick/composite-private.h \
    ../../Include/ImageMagick-6/magick/composite.h \
    ../../Include/ImageMagick-6/magick/compress.h \
    ../../Include/ImageMagick-6/magick/configure.h \
    ../../Include/ImageMagick-6/magick/constitute.h \
    ../../Include/ImageMagick-6/magick/decorate.h \
    ../../Include/ImageMagick-6/magick/delegate-private.h \
    ../../Include/ImageMagick-6/magick/delegate.h \
    ../../Include/ImageMagick-6/magick/deprecate.h \
    ../../Include/ImageMagick-6/magick/display-private.h \
    ../../Include/ImageMagick-6/magick/display.h \
    ../../Include/ImageMagick-6/magick/distort.h \
    ../../Include/ImageMagick-6/magick/draw-private.h \
    ../../Include/ImageMagick-6/magick/draw.h \
    ../../Include/ImageMagick-6/magick/effect.h \
    ../../Include/ImageMagick-6/magick/enhance.h \
    ../../Include/ImageMagick-6/magick/exception-private.h \
    ../../Include/ImageMagick-6/magick/exception.h \
    ../../Include/ImageMagick-6/magick/feature.h \
    ../../Include/ImageMagick-6/magick/fourier.h \
    ../../Include/ImageMagick-6/magick/fx-private.h \
    ../../Include/ImageMagick-6/magick/fx.h \
    ../../Include/ImageMagick-6/magick/gem.h \
    ../../Include/ImageMagick-6/magick/geometry.h \
    ../../Include/ImageMagick-6/magick/hashmap.h \
    ../../Include/ImageMagick-6/magick/histogram.h \
    ../../Include/ImageMagick-6/magick/identify.h \
    ../../Include/ImageMagick-6/magick/image-private.h \
    ../../Include/ImageMagick-6/magick/image-view.h \
    ../../Include/ImageMagick-6/magick/image.h \
    ../../Include/ImageMagick-6/magick/ImageMagick.h \
    ../../Include/ImageMagick-6/magick/layer.h \
    ../../Include/ImageMagick-6/magick/list.h \
    ../../Include/ImageMagick-6/magick/locale_.h \
    ../../Include/ImageMagick-6/magick/log.h \
    ../../Include/ImageMagick-6/magick/mac.h \
    ../../Include/ImageMagick-6/magick/magic.h \
    ../../Include/ImageMagick-6/magick/magick-config.h \
    ../../Include/ImageMagick-6/magick/magick-type.h \
    ../../Include/ImageMagick-6/magick/magick.h \
    ../../Include/ImageMagick-6/magick/MagickCore.h \
    ../../Include/ImageMagick-6/magick/matrix.h \
    ../../Include/ImageMagick-6/magick/memory-private.h \
    ../../Include/ImageMagick-6/magick/memory_.h \
    ../../Include/ImageMagick-6/magick/method-attribute.h \
    ../../Include/ImageMagick-6/magick/methods.h \
    ../../Include/ImageMagick-6/magick/mime-private.h \
    ../../Include/ImageMagick-6/magick/mime.h \
    ../../Include/ImageMagick-6/magick/module.h \
    ../../Include/ImageMagick-6/magick/monitor-private.h \
    ../../Include/ImageMagick-6/magick/monitor.h \
    ../../Include/ImageMagick-6/magick/montage.h \
    ../../Include/ImageMagick-6/magick/morphology-private.h \
    ../../Include/ImageMagick-6/magick/morphology.h \
    ../../Include/ImageMagick-6/magick/nt-base.h \
    ../../Include/ImageMagick-6/magick/nt-feature.h \
    ../../Include/ImageMagick-6/magick/option.h \
    ../../Include/ImageMagick-6/magick/paint.h \
    ../../Include/ImageMagick-6/magick/pixel-accessor.h \
    ../../Include/ImageMagick-6/magick/pixel-private.h \
    ../../Include/ImageMagick-6/magick/pixel.h \
    ../../Include/ImageMagick-6/magick/policy.h \
    ../../Include/ImageMagick-6/magick/prepress.h \
    ../../Include/ImageMagick-6/magick/PreRvIcccm.h \
    ../../Include/ImageMagick-6/magick/profile.h \
    ../../Include/ImageMagick-6/magick/property.h \
    ../../Include/ImageMagick-6/magick/quantize.h \
    ../../Include/ImageMagick-6/magick/quantum-private.h \
    ../../Include/ImageMagick-6/magick/quantum.h \
    ../../Include/ImageMagick-6/magick/random-private.h \
    ../../Include/ImageMagick-6/magick/random_.h \
    ../../Include/ImageMagick-6/magick/registry.h \
    ../../Include/ImageMagick-6/magick/resample-private.h \
    ../../Include/ImageMagick-6/magick/resample.h \
    ../../Include/ImageMagick-6/magick/resize-private.h \
    ../../Include/ImageMagick-6/magick/resize.h \
    ../../Include/ImageMagick-6/magick/resource_.h \
    ../../Include/ImageMagick-6/magick/segment.h \
    ../../Include/ImageMagick-6/magick/semaphore-private.h \
    ../../Include/ImageMagick-6/magick/semaphore.h \
    ../../Include/ImageMagick-6/magick/shear.h \
    ../../Include/ImageMagick-6/magick/signature-private.h \
    ../../Include/ImageMagick-6/magick/signature.h \
    ../../Include/ImageMagick-6/magick/splay-tree.h \
    ../../Include/ImageMagick-6/magick/static.h \
    ../../Include/ImageMagick-6/magick/statistic.h \
    ../../Include/ImageMagick-6/magick/stream-private.h \
    ../../Include/ImageMagick-6/magick/stream.h \
    ../../Include/ImageMagick-6/magick/string-private.h \
    ../../Include/ImageMagick-6/magick/string_.h \
    ../../Include/ImageMagick-6/magick/studio.h \
    ../../Include/ImageMagick-6/magick/thread-private.h \
    ../../Include/ImageMagick-6/magick/thread_.h \
    ../../Include/ImageMagick-6/magick/threshold.h \
    ../../Include/ImageMagick-6/magick/timer.h \
    ../../Include/ImageMagick-6/magick/token-private.h \
    ../../Include/ImageMagick-6/magick/token.h \
    ../../Include/ImageMagick-6/magick/transform.h \
    ../../Include/ImageMagick-6/magick/type.h \
    ../../Include/ImageMagick-6/magick/utility-private.h \
    ../../Include/ImageMagick-6/magick/utility.h \
    ../../Include/ImageMagick-6/magick/version.h \
    ../../Include/ImageMagick-6/magick/vms.h \
    ../../Include/ImageMagick-6/magick/widget.h \
    ../../Include/ImageMagick-6/magick/xml-tree.h \
    ../../Include/ImageMagick-6/magick/xwindow-private.h \
    ../../Include/ImageMagick-6/magick/xwindow.h \
    ../../Include/ImageMagick-6/Magick++/Blob.h \
    ../../Include/ImageMagick-6/Magick++/BlobRef.h \
    ../../Include/ImageMagick-6/Magick++/CoderInfo.h \
    ../../Include/ImageMagick-6/Magick++/Color.h \
    ../../Include/ImageMagick-6/Magick++/Drawable.h \
    ../../Include/ImageMagick-6/Magick++/Exception.h \
    ../../Include/ImageMagick-6/Magick++/Functions.h \
    ../../Include/ImageMagick-6/Magick++/Geometry.h \
    ../../Include/ImageMagick-6/Magick++/Image.h \
    ../../Include/ImageMagick-6/Magick++/ImageRef.h \
    ../../Include/ImageMagick-6/Magick++/Include.h \
    ../../Include/ImageMagick-6/Magick++/Montage.h \
    ../../Include/ImageMagick-6/Magick++/Options.h \
    ../../Include/ImageMagick-6/Magick++/Pixels.h \
    ../../Include/ImageMagick-6/Magick++/STL.h \
    ../../Include/ImageMagick-6/Magick++/Thread.h \
    ../../Include/ImageMagick-6/Magick++/TypeMetric.h \
    ../../Include/ImageMagick-6/wand/animate.h \
    ../../Include/ImageMagick-6/wand/compare.h \
    ../../Include/ImageMagick-6/wand/composite.h \
    ../../Include/ImageMagick-6/wand/conjure.h \
    ../../Include/ImageMagick-6/wand/convert.h \
    ../../Include/ImageMagick-6/wand/deprecate.h \
    ../../Include/ImageMagick-6/wand/display.h \
    ../../Include/ImageMagick-6/wand/drawing-wand.h \
    ../../Include/ImageMagick-6/wand/identify.h \
    ../../Include/ImageMagick-6/wand/import.h \
    ../../Include/ImageMagick-6/wand/magick-image.h \
    ../../Include/ImageMagick-6/wand/magick-property.h \
    ../../Include/ImageMagick-6/wand/magick-wand-private.h \
    ../../Include/ImageMagick-6/wand/magick-wand.h \
    ../../Include/ImageMagick-6/wand/magick_wand.h \
    ../../Include/ImageMagick-6/wand/MagickWand.h \
    ../../Include/ImageMagick-6/wand/method-attribute.h \
    ../../Include/ImageMagick-6/wand/mogrify-private.h \
    ../../Include/ImageMagick-6/wand/mogrify.h \
    ../../Include/ImageMagick-6/wand/montage.h \
    ../../Include/ImageMagick-6/wand/pixel-iterator.h \
    ../../Include/ImageMagick-6/wand/pixel-wand-private.h \
    ../../Include/ImageMagick-6/wand/pixel-wand.h \
    ../../Include/ImageMagick-6/wand/stream.h \
    ../../Include/ImageMagick-6/wand/studio.h \
    ../../Include/ImageMagick-6/wand/wand-config.h \
    ../../Include/ImageMagick-6/wand/wand-view.h \
    ../../Include/ImageMagick-6/wand/wand.h \
    ../../Include/ImageMagick-6/Magick++.h \
    ../../Include/vulkan/GLSL.std.450.h \
    ../../Include/vulkan/libspirv.h \
    ../../Include/vulkan/spirv.h \
    ../../Include/vulkan/spirv.hpp \
    ../../Include/vulkan/vk_icd.h \
    ../../Include/vulkan/vk_layer.h \
    ../../Include/vulkan/vk_platform.h \
    ../../Include/vulkan/vk_sdk_platform.h \
    ../../Include/vulkan/vulkan.h \
    ../../Include/vulkan/vulkan.hpp \
    ../../Include/DR_GameShader.h \
    ../../Include/DR_Pipeline.h \
    ../../Include/DR_Spectator.h \
    ../../Include/DR_ModelLoader.h \
    ../../Include/SOIL/src/image_DXT.h \
    ../../Include/SOIL/src/image_helper.h \
    ../../Include/SOIL/src/SOIL.h \
    ../../Include/SOIL/src/stb_image_aug.h \
    ../../Include/SOIL/src/stbi_DDS_aug.h \
    ../../Include/SOIL/src/stbi_DDS_aug_c.h \
    ../../Include/DR_Skybox.h \
    ../../Include/DR_Texture.h

