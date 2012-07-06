/**
 * @file Singleton.h
 *
 * @author Tag Ashby
 * @date 7/2012
 *
 * This template taken from http://www.yolinux.com/TUTORIALS/C++Singleton.html
 */

#ifndef SINGLETON
#define SINGLETON

namespace TGA
{
   template<class T> class Singleton
   {
   public:
      /// Get a pointer to the singleton
      static T* GetSingletonPtr()
      {
         if (!m_Instance)
         {
            m_Instance = new T;
         }

         return m_Instance;
      }

   private:
      Singleton();
      ~Singleton();
      Singleton(Singleton const&);
      Singleton& operator=(Singleton const&);
      static T* m_Instance;
   };

   template<class T> T* Singleton<T>::m_Instance = NULL;
}

#endif
