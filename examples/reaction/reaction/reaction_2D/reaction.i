 [Mesh]
type = GeneratedMesh
dim = 2
xmin = -20
xmax = 20
nx = 400
elem_type = QUAD9
[]

[Variables]
[./reactionDiff]
order = SECOND
family = LAGRANGE
[../]
[]
 
[Functions]
 [./initial_condition_funct]
type = ParsedFunction
value = '0.7*exp(-x^2)'
 [../]
[]

[ICs]
[./u_ic]
type = FunctionIC
variable = reactionDiff
function = initial_condition_funct
[../]
[]

[Kernels]
[./constant_diff]
type = Diffusion
variable = reactionDiff
[../]
[./reaction]
type = ExampleReaction
variable = reactionDiff
a = 1
alpha = 0.1
[../]
[./time_dev]
type = TimeDerivative
variable = reactionDiff
[../]
[]

[BCs]

[./left]
type = NeumannBC
variable = reactionDiff
boundary = 'left'
[../]
[./right]
type = NeumannBC
variable = reactionDiff
boundary = 'right'
[../]
[]

[Executioner]
type = Transient
solve_type = 'Newton'
num_steps = 40
dt = 1
[]

[Outputs]
execute_on = 'timestep_end'
exodus = true
[]
