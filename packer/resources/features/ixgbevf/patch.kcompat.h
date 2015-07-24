--- /usr/src/ixgbevf-2.16.1/src/kcompat.h.orig  2015-02-03 18:34:22.901474028 +0000
+++ /usr/src/ixgbevf-2.16.1/src/kcompat.h       2015-02-03 18:35:32.577440102 +0000
@@ -3219,8 +3219,6 @@
 #define u64_stats_update_begin(a) do { } while(0)
 #define u64_stats_update_end(a) do { } while(0)
 #define u64_stats_fetch_begin(a) do { } while(0)
-#define u64_stats_fetch_retry_bh(a) (0)
-#define u64_stats_fetch_begin_bh(a) (0)
 
 #if (RHEL_RELEASE_CODE && RHEL_RELEASE_CODE >= RHEL_RELEASE_VERSION(6,1))
 #define HAVE_8021P_SUPPORT
@@ -4174,8 +4172,8 @@
 
 /*****************************************************************************/
 #if ( LINUX_VERSION_CODE < KERNEL_VERSION(3,15,0) )
-#define u64_stats_fetch_begin_irq u64_stats_fetch_begin_bh
-#define u64_stats_fetch_retry_irq u64_stats_fetch_retry_bh
+#define u64_stats_fetch_begin_irq(a) (0)
+#define u64_stats_fetch_retry_irq(a, b) (0) 
 #else
 #define HAVE_PTP_1588_CLOCK_PINS
 #define HAVE_NETDEV_PORT