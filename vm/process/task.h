// task.h
//
// Created on: Jul 3, 2020
//     Author: Jeff Manzione

#ifndef VM_PROCESS_TASK_H_
#define VM_PROCESS_TASK_H_

#include "entity/entity.h"
#include "vm/process/processes.h"

const char *task_state_str(TaskState state);
const char *wait_reason_str(WaitReason reason);

void task_init(Task *task);
void task_finalize(Task *task);
Context *task_create_context(Task *task, Object *self, Module *module,
                             uint32_t instruction_pos);
Context *task_back_context(Task *task);

Entity task_popstack(Task *task);
const Entity *task_peekstack(Task *task);
void task_dropstack(Task *task);
Entity *task_pushstack(Task *task);

const Entity *task_get_resval(Task *task);
Entity *task_mutable_resval(Task *task);

Context *task_get_context_for_index(Task *task, uint32_t index);
Context *task_get_last_context(Task *task);
uint32_t task_context_count(const Task *const task);

#endif /* VM_PROCESS_TASK_H_ */