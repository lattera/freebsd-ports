--- cpp.orig/include/Ice/ConnectionIF.h	2011-06-15 21:43:58.000000000 +0200
+++ cpp/include/Ice/ConnectionIF.h	2012-03-04 20:14:52.000000000 +0100
@@ -17,13 +17,13 @@
 {
 
 class ConnectionI;
+ICE_API Ice::LocalObject* upCast(Ice::ConnectionI*);
 
 }
 
 namespace IceInternal
 {
 
-ICE_API Ice::LocalObject* upCast(Ice::ConnectionI*);
 
 enum AsyncStatus
 {
