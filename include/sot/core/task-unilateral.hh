/*
 * Copyright 2010,
 * François Bleibel,
 * Olivier Stasse,
 *
 * CNRS/AIST
 *
 */

#ifndef __SOT_TASKUNILATERAL_H__
#define __SOT_TASKUNILATERAL_H__

/* --------------------------------------------------------------------- */
/* --- INCLUDE --------------------------------------------------------- */
/* --------------------------------------------------------------------- */

/* Matrix */
#include <dynamic-graph/linear-algebra.h>
namespace dg = dynamicgraph;

/* STD */
#include <string>

/* SOT */
#include <sot/core/feature-abstract.hh>
#include <sot/core/flags.hh>
#include <sot/core/task.hh>

#include <sot/core/exception-task.hh>

/* --------------------------------------------------------------------- */
/* --- API ------------------------------------------------------------- */
/* --------------------------------------------------------------------- */

#if defined(WIN32)
#if defined(task_unilateral_EXPORTS)
#define SOTTASKUNILATERAL_EXPORT __declspec(dllexport)
#else
#define SOTTASKUNILATERAL_EXPORT __declspec(dllimport)
#endif
#else
#define SOTTASKUNILATERAL_EXPORT
#endif

/* --------------------------------------------------------------------- */
/* --- CLASS ----------------------------------------------------------- */
/* --------------------------------------------------------------------- */

namespace dynamicgraph {
namespace sot {
namespace dg = dynamicgraph;

class SOTTASKUNILATERAL_EXPORT TaskUnilateral : public Task {
protected:
  std::list<FeatureAbstract *> featureList;

public:
  static const std::string CLASS_NAME;
  virtual const std::string &getClassName(void) const { return CLASS_NAME; }

public:
  TaskUnilateral(const std::string &n);

  /* --- COMPUTATION --- */
  VectorMultiBound &computeTaskUnilateral(VectorMultiBound &res, int time);

  /* --- SIGNALS ------------------------------------------------------------ */
public:
  dg::SignalPtr<dg::Vector, int> positionSIN;
  dg::SignalPtr<dg::Vector, int> referenceInfSIN;
  dg::SignalPtr<dg::Vector, int> referenceSupSIN;
  dg::SignalPtr<double, int> dtSIN;

  /* --- DISPLAY ------------------------------------------------------------ */
  void display(std::ostream &os) const;
};

} /* namespace sot */
} /* namespace dynamicgraph */

#endif /* #ifndef __SOT_TASKUNILATERAL_H__ */
