--- cpp.orig/src/slice2rb/Main.cpp	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/slice2rb/Main.cpp	2012-09-10 11:43:58.000000000 +0200
@@ -39,7 +39,7 @@ using namespace Slice::Ruby;
 namespace
 {
 
-IceUtil::Mutex* mutex = 0;
+IceUtil::Mutex* mtx = 0;
 bool interrupted = false;
 
 class Init
@@ -48,13 +48,13 @@ public:
 
     Init()
     {
-        mutex = new IceUtil::Mutex;
+        mtx = new IceUtil::Mutex;
     }
 
     ~Init()
     {
-        delete mutex;
-        mutex = 0;
+        delete mtx;
+        mtx = 0;
     }
 };
 
@@ -65,7 +65,7 @@ Init init;
 void
 interruptedCallback(int signal)
 {
-    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
     interrupted = true;
 }
@@ -316,7 +316,7 @@ compile(int argc, char* argv[])
         }
 
         {
-            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mutex);
+            IceUtilInternal::MutexPtrLock<IceUtil::Mutex> sync(mtx);
 
             if(interrupted)
             {
