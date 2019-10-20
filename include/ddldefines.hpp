//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_DDLDEFINES_HPP
#define CPPPYPLOT_DDLDEFINES_HPP

#if defined (_WIN32)
#if defined(cppplot_EXPORT)
#define  CPPPLOT_EXPORT __declspec(dllexport)
#else
#define  CPPPLOT_EXPORT __declspec(dllimport)
#endif
#else
#define CPPPLOT_EXPORT
#endif

#endif //CPPPYPLOT_DDLDEFINES_HPP
