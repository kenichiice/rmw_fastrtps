// Copyright 2016-2018 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RMW_FASTRTPS_SHARED_CPP__RMW_COMMON_HPP_
#define RMW_FASTRTPS_SHARED_CPP__RMW_COMMON_HPP_

#include "./visibility_control.h"

#include "rmw/error_handling.h"
#include "rmw/event.h"
#include "rmw/features.h"
#include "rmw/rmw.h"
#include "rmw/topic_endpoint_info_array.h"
#include "rmw/types.h"
#include "rmw/names_and_types.h"
#include "rmw/network_flow_endpoint_array.h"

namespace rmw_fastrtps_shared_cpp
{

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_client(
  const char * identifier,
  rmw_node_t * node,
  rmw_client_t * client);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_compare_gids_equal(
  const char * identifier,
  const rmw_gid_t * gid1,
  const rmw_gid_t * gid2,
  bool * result);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_count_publishers(
  const char * identifier,
  const rmw_node_t * node,
  const char * topic_name,
  size_t * count);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_count_subscribers(
  const char * identifier,
  const rmw_node_t * node,
  const char * topic_name,
  size_t * count);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_gid_for_publisher(
  const char * identifier,
  const rmw_publisher_t * publisher,
  rmw_gid_t * gid);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_gid_for_client(
  const char * identifier,
  const rmw_client_t * client,
  rmw_gid_t * gid);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_guard_condition_t *
__rmw_create_guard_condition(const char * identifier);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_guard_condition(rmw_guard_condition_t * guard_condition);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_trigger_guard_condition(
  const char * identifier,
  const rmw_guard_condition_t * guard_condition_handle);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_set_log_severity(rmw_log_severity_t severity);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_node_t *
__rmw_create_node(
  rmw_context_t * context,
  const char * identifier,
  const char * name,
  const char * namespace_);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_node(
  const char * identifier,
  rmw_node_t * node);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
const rmw_guard_condition_t *
__rmw_node_get_graph_guard_condition(const rmw_node_t * node);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_node_names(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_string_array_t * node_names,
  rcutils_string_array_t * node_namespaces);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_init_event(
  const char * identifier,
  rmw_event_t * rmw_event,
  const char * topic_endpoint_impl_identifier,
  void * data,
  rmw_event_type_t event_type);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_node_names_with_enclaves(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_string_array_t * node_names,
  rcutils_string_array_t * node_namespaces,
  rcutils_string_array_t * enclaves);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publish(
  const char * identifier,
  const rmw_publisher_t * publisher,
  const void * ros_message,
  rmw_publisher_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publish_serialized_message(
  const char * identifier,
  const rmw_publisher_t * publisher,
  const rmw_serialized_message_t * serialized_message,
  rmw_publisher_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_borrow_loaned_message(
  const char * identifier,
  const rmw_publisher_t * publisher,
  const rosidl_message_type_support_t * type_support,
  void ** ros_message);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_return_loaned_message_from_publisher(
  const char * identifier,
  const rmw_publisher_t * publisher,
  void * loaned_message);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publish_loaned_message(
  const char * identifier,
  const rmw_publisher_t * publisher,
  const void * ros_message,
  rmw_publisher_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publisher_assert_liveliness(
  const char * identifier,
  const rmw_publisher_t * publisher);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publisher_wait_for_all_acked(
  const char * identifier,
  const rmw_publisher_t * publisher,
  rmw_time_t wait_timeout);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_publisher(
  const char * identifier,
  const rmw_node_t * node,
  rmw_publisher_t * publisher);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publisher_count_matched_subscriptions(
  const rmw_publisher_t * publisher,
  size_t * subscription_count);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publisher_get_actual_qos(
  const rmw_publisher_t * publisher,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_send_request(
  const char * identifier,
  const rmw_client_t * client,
  const void * ros_request,
  int64_t * sequence_id);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_request(
  const char * identifier,
  const rmw_service_t * service,
  rmw_service_info_t * request_header,
  void * ros_request,
  bool * taken);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_response(
  const char * identifier,
  const rmw_client_t * client,
  rmw_service_info_t * request_header,
  void * ros_response,
  bool * taken);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_send_response(
  const char * identifier,
  const rmw_service_t * service,
  rmw_request_id_t * request_header,
  void * ros_response);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_service(
  const char * identifier,
  rmw_node_t * node,
  rmw_service_t * service);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_service_names_and_types(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  rmw_names_and_types_t * service_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_publisher_names_and_types_by_node(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * node_name,
  const char * node_namespace,
  bool no_demangle,
  rmw_names_and_types_t * topic_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_service_names_and_types_by_node(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * node_name,
  const char * node_namespace,
  rmw_names_and_types_t * service_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_client_names_and_types_by_node(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * node_name,
  const char * node_namespace,
  rmw_names_and_types_t * service_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_subscriber_names_and_types_by_node(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * node_name,
  const char * node_namespace,
  bool no_demangle,
  rmw_names_and_types_t * topic_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_service_server_is_available(
  const char * identifier,
  const rmw_node_t * node,
  const rmw_client_t * client,
  bool * is_available);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_subscription(
  const char * identifier,
  const rmw_node_t * node,
  rmw_subscription_t * subscription,
  bool reset_cft = false);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_count_matched_publishers(
  const rmw_subscription_t * subscription,
  size_t * publisher_count);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_get_actual_qos(
  const rmw_subscription_t * subscription,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_set_content_filter(
  rmw_subscription_t * subscription,
  const rmw_subscription_content_filter_options_t * options);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_get_content_filter(
  const rmw_subscription_t * subscription,
  rcutils_allocator_t * allocator,
  rmw_subscription_content_filter_options_t * options);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_service_response_publisher_get_actual_qos(
  const rmw_service_t * service,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_service_request_subscription_get_actual_qos(
  const rmw_service_t * service,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_client_request_publisher_get_actual_qos(
  const rmw_client_t * client,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_client_response_subscription_get_actual_qos(
  const rmw_client_t * client,
  rmw_qos_profile_t * qos);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take(
  const char * identifier,
  const rmw_subscription_t * subscription,
  void * ros_message,
  bool * taken,
  rmw_subscription_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_sequence(
  const char * identifier,
  const rmw_subscription_t * subscription,
  size_t count,
  rmw_message_sequence_t * message_sequencxe,
  rmw_message_info_sequence_t * message_info_sequence,
  size_t * taken,
  rmw_subscription_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_loaned_message_internal(
  const char * identifier,
  const rmw_subscription_t * subscription,
  void ** loaned_message,
  bool * taken,
  rmw_message_info_t * message_info);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_return_loaned_message_from_subscription(
  const char * identifier,
  const rmw_subscription_t * subscription,
  void * loaned_message);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_event(
  const char * identifier,
  const rmw_event_t * event_handle,
  void * event_info,
  bool * taken);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_with_info(
  const char * identifier,
  const rmw_subscription_t * subscription,
  void * ros_message,
  bool * taken,
  rmw_message_info_t * message_info,
  rmw_subscription_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_serialized_message(
  const char * identifier,
  const rmw_subscription_t * subscription,
  rmw_serialized_message_t * serialized_message,
  bool * taken,
  rmw_subscription_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_take_serialized_message_with_info(
  const char * identifier,
  const rmw_subscription_t * subscription,
  rmw_serialized_message_t * serialized_message,
  bool * taken,
  rmw_message_info_t * message_info,
  rmw_subscription_allocation_t * allocation);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_topic_names_and_types(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  bool no_demangle,
  rmw_names_and_types_t * topic_names_and_types);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_wait(
  const char * identifier,
  rmw_subscriptions_t * subscriptions,
  rmw_guard_conditions_t * guard_conditions,
  rmw_services_t * services,
  rmw_clients_t * clients,
  rmw_events_t * events,
  rmw_wait_set_t * wait_set,
  const rmw_time_t * wait_timeout);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_wait_set_t *
__rmw_create_wait_set(const char * identifier, rmw_context_t * context, size_t max_conditions);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_destroy_wait_set(const char * identifier, rmw_wait_set_t * wait_set);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_publishers_info_by_topic(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * topic_name,
  bool no_mangle,
  rmw_topic_endpoint_info_array_t * publishers_info);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_get_subscriptions_info_by_topic(
  const char * identifier,
  const rmw_node_t * node,
  rcutils_allocator_t * allocator,
  const char * topic_name,
  bool no_mangle,
  rmw_topic_endpoint_info_array_t * subscriptions_info);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_qos_profile_check_compatible(
  const rmw_qos_profile_t publisher_profile,
  const rmw_qos_profile_t subscription_profile,
  rmw_qos_compatibility_type_t * compatibility,
  char * reason,
  size_t reason_size);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_publisher_get_network_flow_endpoints(
  const rmw_publisher_t * publisher,
  rcutils_allocator_t * allocator,
  rmw_network_flow_endpoint_array_t * network_flow_endpoint_array);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_get_network_flow_endpoints(
  const rmw_subscription_t * subscription,
  rcutils_allocator_t * allocator,
  rmw_network_flow_endpoint_array_t * network_flow_endpoint_array);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_subscription_set_on_new_message_callback(
  rmw_subscription_t * rmw_subscription,
  rmw_event_callback_t callback,
  const void * user_data);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_service_set_on_new_request_callback(
  rmw_service_t * rmw_service,
  rmw_event_callback_t callback,
  const void * user_data);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_client_set_on_new_response_callback(
  rmw_client_t * rmw_client,
  rmw_event_callback_t callback,
  const void * user_data);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
rmw_ret_t
__rmw_event_set_callback(
  rmw_event_t * rmw_event,
  rmw_event_callback_t callback,
  const void * user_data);

RMW_FASTRTPS_SHARED_CPP_PUBLIC
bool
__rmw_feature_supported(rmw_feature_t feature);

}  // namespace rmw_fastrtps_shared_cpp

#endif  // RMW_FASTRTPS_SHARED_CPP__RMW_COMMON_HPP_
