---
title: "TPL reading notes"
tags: [PL, books]
---

pragmatism

## Chapter 1: Intro
### Types in CS
Some poweful frameworks to ensure that a system behaves correctly:
+ Hoare logic
+ algebraic secification
+ modal logics
+ denotational semantics
disadvantages: cumbersome to use  
Other lightweight ways:
+ model checkers
  - tools that search for errors in finite-state systems such as chip designs or communication protocols
+ run-time monitoring
  - a collection of techniques that allow a stsrem to detect, dynamically, when one of its components is not behaveing according to specification.
+ type system
  - BEST
  - prove the absence of sth?
Two branches to the study of type systems.
+ practical one (main focus this book)
+ abstract one (focus between various "pure typed lambda-calculi" and varisties of logic, via Curry-Howard correspondence in orientation)
Some languages sacrifice the guarantee to terminate of well-typed computation for the sake of features like recursive function definitions. (can't have both? why?)
