--- cpp.orig/src/Glacier2/Blobject.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/src/Glacier2/Blobject.h	2012-03-04 19:39:27.000000000 +0100
@@ -24,6 +24,8 @@
     Blobject(const InstancePtr&, const Ice::ConnectionPtr&, const Ice::Context&);
     virtual ~Blobject();
 
+    void destroy();
+
 protected:
 
     void invoke(Ice::ObjectPrx&, const Ice::AMD_Object_ice_invokePtr&, 
