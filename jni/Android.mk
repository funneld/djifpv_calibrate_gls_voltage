LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CFLAGS += -fPIC -std=c99
LOCAL_LDFLAGS += -fPIC
LOCAL_LDLIBS := -llog

LOCAL_MODULE    := calibrate_gls_voltage
LOCAL_SRC_FILES := calibrate_gls_voltage.c

include $(BUILD_SHARED_LIBRARY)
