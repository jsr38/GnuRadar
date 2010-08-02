// Copyright (c) 2010 Ryan Seal <rlseal -at- gmail.com>
//
// This file is part of GnuRadar Software.
//
// GnuRadar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//  
// GnuRadar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with GnuRadar.  If not, see <http://www.gnu.org/licenses/>.
#ifndef PRODUCER_THREAD_H
#define PRODUCER_THREAD_H

#include <gnuradar/BaseThread.h>
#include <gnuradar/SThread.h>
#include <gnuradar/Device.h>

/// This class inherits from Sthread and is responsible for 
/// collecting data from the hardware device and transferring
/// it to the shared buffer memory region.
class ProducerThread: public BaseThread, public SThread{
   Device& device_;

   public:

   /// Constructor
   /// \param bytes data write size in bytes
   /// \param device GnuRadar device reference
   ProducerThread(const int bytes, Device& device):
      BaseThread(bytes),SThread(),device_(device){ }

   /// stops the device
   virtual void Stop(){ device_.Stop(); }

   /// executes worker thread
   virtual void RequestData(void* address){
      address_ = address;
      this->Start();
   }

   /// worker thread - see implementation file for details.
   virtual void Run();
};    

#endif
