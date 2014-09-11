#include <stdio.h>
#include <gst/gst.h>
#include <gst/gstversion.h>

int main(int argc, char *argv[])
{
  printf("Compiled with GStreamer %d.%d.%d\n",
    GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    GST_VERSION_MICRO);
  return 0;
}
