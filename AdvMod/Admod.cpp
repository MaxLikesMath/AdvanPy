#include <Python.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "C:/Advantech/DAQNavi/Inc/bdaqctrl.h"
#include "C:/Advantech/DAQNavi/Examples/C++_Console/inc/compatibility.h"

using namespace Automation::BDaq;
///typedef defines a variable name "byte" to the datatype unsigned variable, allowing us to call it as a byte.
typedef unsigned char byte;
#define  deviceDescription  L"USB-4718,BID#0"
ErrorCode ret;

// Step 1: create 'InstantDiCtrl' object
InstantDiCtrl * ctrlI = InstantDiCtrl::Create();
InstantDoCtrl * ctrlO = InstantDoCtrl::Create();
DeviceInformation devInfo(deviceDescription);

PyObject* DI(PyObject *) {


		ret = ctrlI->setSelectedDevice(devInfo);

		// Step 3: Scan the ports
		int32 const portStart = 0;
		int32 const portCount = 1;
		byte        values[portCount];



		ret = ctrlI->Read(portStart, portCount, values);
		if (ret == Success) {
			return PyLong_FromLong((long)values[0]);

		}
		else {
			return nullptr;
		}




};

PyObject* DO_ON(PyObject*) {

	ret = ctrlO->setSelectedDevice(devInfo);
	// Step 3: Scan the ports
	int32 const portStart = 0;
	int32 const portCount = 1;
	byte        bufferForWriting[64] = {1};



	ret = ctrlO->Write(portStart, portCount, bufferForWriting);
	return Py_BuildValue("");
}

PyObject* DO_OFF(PyObject*) {

	ret = ctrlO->setSelectedDevice(devInfo);
	// Step 3: Scan the ports
	int32 const portStart = 0;
	int32 const portCount = 1;
	byte        bufferForWriting[64] = { 0 };



	ret = ctrlO->Write(portStart, portCount, bufferForWriting);
	return Py_BuildValue("");
}


static PyMethodDef advantech_methods[] = {
	{ "AdDI", (PyCFunction)DI, METH_O, nullptr },
	{ "AdDO_ON", (PyCFunction)DO_ON, METH_O, nullptr },
	{ "AdDO_OFF", (PyCFunction)DO_OFF, METH_O, nullptr },
{ nullptr, nullptr, 0, nullptr }
};


static PyModuleDef advantechDIO_module = {
	PyModuleDef_HEAD_INIT,
	"advantechDIO",                        // Module name to use with Python import statements
	"Works With Advantech I/O box",  // Module description
	0,
	advantech_methods                   // Structure that defines the methods of the module
};


PyMODINIT_FUNC PyInit_AdvMod() {
	return PyModule_Create(&advantechDIO_module);
};